module.exports = grammar({
  name: 'rf',
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
      'type',
      field('name', $.identifier),
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
      $.integer_type
    ),

    integer_type: $ => seq(
      'integer',
      '<',
      field('size', $.number),
      ',',
      field('signed', $.boolean),
      '>'
    ),

    block: $ => seq(
      '{',
       repeat($._statement),
       '}'
    ),

    _statement: $ => choice(
      $.return_statement,
      seq($._expression, ';')
    ),

    return_statement: $ => seq(
      'return',
      optional(field('value', $._expression)),
      ';'
    ),

    _expression: $ => choice(
      $.identifier,
      $.scoped_identifier,
      $.number,
      $.call_expression,
      $.binary_expression,
      // TODO: other kinds of expressions
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

    binary_expression: $ => prec.left(seq(
      field('left', $._expression),
      field('operator', $.operator),
      field('right', $._expression)
    )),

    identifier: $ => /[a-zA-Z_][a-zA-Z_0-9]*/,
    scoped_identifier: $ => seq(
      field('left', choice(
        $.identifier,
        $.scoped_identifier
      )),
      '.',
      field('right', $.identifier)
    ),

    number: $ => /\d+/,
    boolean: $ => choice(
      'true',
      'false'
    ),
    operator: $ => choice('+', '*', '/', '-'),
  }
});
