module.exports = grammar({
  name: 'lart',

  extras: $ => [
    $.line_comment,
    $.block_comment,
    /\s/,
  ],

  rules: {
    source_file: $ => repeat($._definition),
    _definition: $ => choice(
      $.function,
      $.module,
      $.typedef
    ),

    module: $ => seq(
      'mod',
      field('name', $.identifier),
      '{',
      repeat($._definition),
      '}'
    ),

    typedef: $ => seq(
      'typedef',
      field('name', $.identifier),
      '=',
      field('type', $._type),
      ';'
    ),

    function: $ => seq(
      'fn',
      field('name', $.identifier),
      field('parameters', $.parameter_list),
      optional(seq('->', field('type', $._type))),
      choice(field('body', $.block), ';')
    ),

    parameter_list: $ => seq(
      '(',
      optional(seq(
        $.parameter,
        repeat(seq(',', $.parameter))
      )),
      ')'
    ),

    parameter: $ => seq(
      field('name', $.identifier),
      ':',
      field('type', $._type)
    ),

    _type: $ => choice(
      $.identifier,
      $.scoped_identifier,
      $.integer_type,
      $.double_type,
      $.boolean_type,
      $.pointer_type,
      $.struct_type,
      $.function_type,
    ),

    integer_type: $ => seq(
      'integer',
      '<',
      field('size', $.integer),
      ',',
      field('signed', $.boolean),
      '>'
    ),

    double_type: $ => seq(
      'double',
      '<',
      field('size', $.integer),
      '>'
    ),

    boolean_type: $ => seq(
      'bool'
    ),

    pointer_type: $ => seq(
      '&',
      field('type', $._type)
    ),

    struct_type: $ => seq(
      'struct',
      field('fields', $.field_list)
    ),

    function_type: $ => seq(
      '&',
      field('parameters', $.type_list),
      optional(seq('->', field('type', $._type))),
    ),

    type_list: $ => seq(
      '(',
      optional(seq(
        $._type,
        repeat(seq(',', $._type))
      )),
      ')'
    ),

    field_list: $ => seq(
      '{',
      optional(seq(
        $.field,
        repeat(seq(',', $.field))
      )),
      '}'
    ),

    field: $ => seq(
      field('name', $.identifier),
      ':',
      field('type', $._type)
    ),

    block: $ => seq(
      '{',
       repeat($._statement),
       '}'
    ),

    _statement: $ => choice(
      $.let_statement,
      $.const_statement,
      $.return_statement,
      $.break_statement,
      $.continue_statement,
      $.if_else,
      $.while,
      $.for,
      $.block,
      seq($._expression, ';')
    ),

    return_statement: $ => seq(
      'return',
      optional(field('value', $._expression)),
      ';'
    ),

    break_statement: $ => seq(
      'break',
      ';'
    ),

    continue_statement: $ => seq(
      'continue',
      ';'
    ),

    if_else: $ => prec.left(seq(
      'if',
      '(',
      field('condition', $._expression),
      ')',
      field('then', $._statement),
      optional(seq(
        'else',
        field('else', $._statement)
      ))
    )),

    while: $ => seq(
      'while',
      '(',
      field('condition', $._expression),
      ')',
      field('body', $._statement)
    ),

    for: $ => seq(
      'for',
      '(',
      field('init', $._statement),
      field('condition', $._expression),
      ';',
      field('step', $._expression),
      ')',
      field('body', $._statement)
    ),

    let_statement: $ => seq(
      'let',
      field('name', $.identifier),
      ':',
      field('type', $._type),
      optional(seq(
        '=',
        field('value', $._expression)
      )),
      ';'
    ),

    const_statement: $ => seq(
      'const',
      field('name', $.identifier),
      ':',
      field('type', $._type),
      optional(seq(
        '=',
        field('value', $._expression)
      )),
      ';'
    ),

    _expression: $ => choice(
      $.identifier,
      $.scoped_identifier,
      $.integer,
      $.double,
      $.boolean,
      $.nullptr,
      $.character,
      $.string,
      $.call_expression,
      $.binary_expression,
      $.monary_expression,
      $.sizeof_expression,
      seq('(', $._expression, ')'),
      $.cast_expression,
      $.bitcast_expression,
    ),

    call_expression: $ => seq(
      field('callable', $._expression),
      field('arguments', $.argument_list)
    ),

    argument_list: $ => seq(
      '(',
      optional(seq(
        $._expression,
        repeat(seq(',', $._expression))
      )),
      ')'
    ),

    binary_expression: $ => prec.right(1, seq(
      field('left', $._expression),
      field('operator', $.binary_operator),
      field('right', $._expression)
    )),

    monary_expression: $ => prec.right(2, seq(
      field('operator', $.monary_operator),
      field('value', $._expression)
    )),

    sizeof_expression: $ => seq(
      'sizeof',
      '(',
      field('type', $._type),
      ')'
    ),

    cast_expression: $ => seq(
      'cast',
      '<',
      field('type', $._type),
      '>',
      '(',
      field('value', $._expression),
      ')'
    ),

    bitcast_expression: $ => seq(
      'bitcast',
      '<',
      field('type', $._type),
      '>',
      '(',
      field('value', $._expression),
      ')'
    ),

    identifier: $ => /[a-zA-Z_][a-zA-Z_0-9]*/,
    scoped_identifier: $ => prec.right(3, seq(
      field('left', choice(
        $.identifier,
        $.scoped_identifier
      )),
      '.',
      field('right', $.identifier)
    )),

    integer: $ => /\d+/,
    double: $ => /\d+\.\d+/,
    boolean: $ => choice(
      'true',
      'false'
    ),
    nullptr: $ => 'nullptr',
    character: $ => token(seq(
      '\'',
      repeat1(choice(
        /[^\\'\n]/,
        /\\./,
        /\\\n/,
      )),
      '\'',
    )),
    string: $ => token(seq(
      '\"',
      repeat1(choice(
        /[^\\"\n]/,
        /\\./,
        /\\\n/,
      )),
      '\"',
    )),

    binary_operator: $ => choice('>=', '<=', '&&', '||', '==', '!=', '<<', '>>', '+', '*', '/', '-', '>', '<', '&', '|', '=', '^', '.'),
    monary_operator: $ => choice('--', '++', '+', '-', '&', '*', '~', '!'),

    comment: $ => choice(
      $.line_comment,
      $.block_comment,
    ),

    line_comment: $ => token(prec(0, seq('//', /[^\n]*/))),
    block_comment: $ => token(prec(0,
      seq(
        '/*',
        /[^*]*\*+([^/*][^*]*\*+)*/,
        '/',
      ),
    )),
  }
});
