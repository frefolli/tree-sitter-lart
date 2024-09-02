; Identifiers

(identifier) @type

; Identifier conventions

; Assume all-caps names are constants
((identifier) @constant
 (#match? @constant "^[A-Z][A-Z\\d_]+$'"))

; Assume uppercase names are enum constructors
((identifier) @constructor
 (#match? @constructor "^[A-Z]"))

; Assume that uppercase names in paths are types
((scoped_identifier
  left: (identifier) @type)
 (#match? @type "^[A-Z]"))
((scoped_identifier
  left: (scoped_identifier
    right: (identifier) @type))
 (#match? @type "^[A-Z]"))

; Function calls

(call_expression
  callable: (identifier) @function)
(call_expression
  callable: (scoped_identifier
    right: (identifier) @function))

; Function definitions

(function (identifier) @function)

(line_comment) @comment
(block_comment) @comment

"(" @punctuation.bracket
")" @punctuation.bracket
"{" @punctuation.bracket
"}" @punctuation.bracket

"::" @punctuation.delimiter
"." @punctuation.delimiter
"," @punctuation.delimiter
";" @punctuation.delimiter

(parameter name: (identifier) @variable.parameter)
(parameter type: (identifier) @variable.type)

"break" @keyword
"const" @keyword
"continue" @keyword
"else" @keyword
"fn" @keyword
"for" @keyword
"if" @keyword
"let" @keyword
"mod" @keyword
"return" @keyword
"struct" @keyword
"typedef" @keyword
"while" @keyword

(character) @string
(string) @string

(boolean) @constant.builtin
(integer) @constant.builtin
(double) @constant.builtin

"*" @operator
"&" @operator
"+" @operator
"-" @operator
"/" @operator
"==" @operator
"||" @operator
"!=" @operator
">=" @operator
"<=" @operator
">>" @operator
"<<" @operator
"++" @operator
"--" @operator
"=" @operator
">" @operator
"<" @operator
"|" @operator
"~" @operator
"!" @operator
