module.exports = grammar({
  name: 'lart',

  conflicts: $ => [
    [$._expression, $._callable_expression],
    [$.callable_binary_expression, $.binary_expression]
  ],

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
      $.void_type,
    ),

    void_type: $ => 'void',

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
      field('parameters', $.parameter_list),
      optional(seq('->', field('type', $._type))),
    ),

    /* TODO: Remove
    type_list: $ => seq(
      '(',
      optional(seq(
        $._type,
        repeat(seq(',', $._type))
      )),
      ')'
    ),
    */

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
      $.parenthesized_expression,
      $.cast_expression,
      $.bitcast_expression,
      $.identifier,
      $.scoped_identifier,
    ),

    _callable_expression: $ => choice(
      $.call_expression,
      $.identifier,
      $.scoped_identifier,
      $.callable_binary_expression,
      $.parenthesized_expression
    ),

    parenthesized_expression: $ => seq('(', $._expression, ')'),

    call_expression: $ => seq(
      field('callable', $._callable_expression),
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

    callable_binary_expression: $ => choice(
      $._binary_expression_dot,
      $._binary_expression_arr,
    ),

    binary_expression: $ => choice(
      $._binary_expression_dot,
      $._binary_expression_arr,
      $._binary_expression_xor,
      $._binary_expression_mul,
      $._binary_expression_div,
      $._binary_expression_add,
      $._binary_expression_sub,
      $._binary_expression_ge,
      $._binary_expression_le,
      $._binary_expression_sca,
      $._binary_expression_sco,
      $._binary_expression_eq,
      $._binary_expression_ne,
      $._binary_expression_lrot,
      $._binary_expression_rrot,
      $._binary_expression_gr,
      $._binary_expression_lr,
      $._binary_expression_and,
      $._binary_expression_or,
      $._binary_expression_ass,
    ),

    monary_expression: $ => prec.left(10, seq(
      field('operator', $.monary_operator),
      field('value', $._expression)
    )),

    _binary_expression_dot:  $ => prec.left(9, seq(
      field('left', $._expression),
      field('operator', $.binary_operator_dot),
      field('right', $._expression))),
    _binary_expression_arr:  $ => prec.left(9, seq(
      field('left', $._expression),
      field('operator', $.binary_operator_arr),
      field('right', $._expression))),
    _binary_expression_xor:  $ => prec.left(8, seq(
      field('left', $._expression),
      field('operator', $.binary_operator_xor),
      field('right', $._expression))),
    _binary_expression_mul:  $ => prec.left(7, seq(
      field('left', $._expression),
      field('operator', $.binary_operator_mul),
      field('right', $._expression))),
    _binary_expression_div:  $ => prec.left(7, seq(
      field('left', $._expression),
      field('operator', $.binary_operator_div),
      field('right', $._expression))),
    _binary_expression_add:  $ => prec.left(6, seq(
      field('left', $._expression),
      field('operator', $.binary_operator_add),
      field('right', $._expression))),
    _binary_expression_sub:  $ => prec.left(6, seq(
      field('left', $._expression),
      field('operator', $.binary_operator_sub),
      field('right', $._expression))),
    _binary_expression_ge:  $ => prec.left(5, seq(
      field('left', $._expression),
      field('operator', $.binary_operator_ge),
      field('right', $._expression))),
    _binary_expression_le:  $ => prec.left(5, seq(
      field('left', $._expression),
      field('operator', $.binary_operator_le),
      field('right', $._expression))),
    _binary_expression_sca:  $ => prec.left(5, seq(
      field('left', $._expression),
      field('operator', $.binary_operator_sca),
      field('right', $._expression))),
    _binary_expression_sco:  $ => prec.left(5, seq(
      field('left', $._expression),
      field('operator', $.binary_operator_sco),
      field('right', $._expression))),
    _binary_expression_eq:  $ => prec.left(5, seq(
      field('left', $._expression),
      field('operator', $.binary_operator_eq),
      field('right', $._expression))),
    _binary_expression_ne:  $ => prec.left(5, seq(
      field('left', $._expression),
      field('operator', $.binary_operator_ne),
      field('right', $._expression))),
    _binary_expression_lrot:  $ => prec.left(5, seq(
      field('left', $._expression),
      field('operator', $.binary_operator_lrot),
      field('right', $._expression))),
    _binary_expression_rrot:  $ => prec.left(5, seq(
      field('left', $._expression),
      field('operator', $.binary_operator_rrot),
      field('right', $._expression))),
    _binary_expression_gr:  $ => prec.left(4, seq(
      field('left', $._expression),
      field('operator', $.binary_operator_gr),
      field('right', $._expression))),
    _binary_expression_lr:  $ => prec.left(4, seq(
      field('left', $._expression),
      field('operator', $.binary_operator_lr),
      field('right', $._expression))),
    _binary_expression_and:  $ => prec.left(4, seq(
      field('left', $._expression),
      field('operator', $.binary_operator_and),
      field('right', $._expression))),
    _binary_expression_or:  $ => prec.left(4, seq(
      field('left', $._expression),
      field('operator', $.binary_operator_or),
      field('right', $._expression))),
    _binary_expression_ass:  $ => prec.left(3, seq(
      field('left', $._expression),
      field('operator', $.binary_operator_ass),
      field('right', $._expression))),

    binary_operator_dot: $ => '.',
    binary_operator_arr: $ => '->',
    binary_operator_xor: $ => '^',
    binary_operator_mul: $ => '*',
    binary_operator_div: $ => '/',
    binary_operator_add: $ => '+',
    binary_operator_sub: $ => '-',
    binary_operator_ge: $ => '>=',
    binary_operator_le: $ => '<=',
    binary_operator_sca: $ => '&&',
    binary_operator_sco: $ => '||',
    binary_operator_eq: $ => '==',
    binary_operator_ne: $ => '!=',
    binary_operator_lrot: $ => '<<',
    binary_operator_rrot: $ => '>>',
    binary_operator_gr: $ => '>',
    binary_operator_lr: $ => '<',
    binary_operator_and: $ => '&',
    binary_operator_or: $ => '|',
    binary_operator_ass: $ => '=',

    sizeof_expression: $ => seq(
      'sizeof',
      '<',
      field('type', $._type),
      '>'
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
      '::',
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
    monary_operator: $ => choice(
     '--',
     '++',
     '*',
     '+',
     '-',
     '&',
     '~',
     '!',
    ),

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
