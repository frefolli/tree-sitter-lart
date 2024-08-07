#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 71
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 48
#define ALIAS_COUNT 0
#define TOKEN_COUNT 25
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 12
#define MAX_ALIAS_SEQUENCE_LENGTH 6
#define PRODUCTION_ID_COUNT 13

enum ts_symbol_identifiers {
  anon_sym_mod = 1,
  anon_sym_LBRACE = 2,
  anon_sym_RBRACE = 3,
  anon_sym_type = 4,
  anon_sym_SEMI = 5,
  anon_sym_fn = 6,
  anon_sym_DASH_GT = 7,
  anon_sym_LPAREN = 8,
  anon_sym_COMMA = 9,
  anon_sym_RPAREN = 10,
  anon_sym_COLON = 11,
  anon_sym_integer = 12,
  anon_sym_LT = 13,
  anon_sym_GT = 14,
  anon_sym_return = 15,
  sym_identifier = 16,
  anon_sym_DOT = 17,
  sym_number = 18,
  anon_sym_true = 19,
  anon_sym_false = 20,
  anon_sym_PLUS = 21,
  anon_sym_STAR = 22,
  anon_sym_SLASH = 23,
  anon_sym_DASH = 24,
  sym_source_file = 25,
  sym__definition = 26,
  sym_module = 27,
  sym_typedef = 28,
  sym_function = 29,
  sym_parameter_list = 30,
  sym_parameter = 31,
  sym__type = 32,
  sym_integer_type = 33,
  sym_block = 34,
  sym__statement = 35,
  sym_return_statement = 36,
  sym__expression = 37,
  sym_call_expression = 38,
  sym_argument_list = 39,
  sym_binary_expression = 40,
  sym_scoped_identifier = 41,
  sym_boolean = 42,
  sym_operator = 43,
  aux_sym_source_file_repeat1 = 44,
  aux_sym_parameter_list_repeat1 = 45,
  aux_sym_block_repeat1 = 46,
  aux_sym_argument_list_repeat1 = 47,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_mod] = "mod",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_type] = "type",
  [anon_sym_SEMI] = ";",
  [anon_sym_fn] = "fn",
  [anon_sym_DASH_GT] = "->",
  [anon_sym_LPAREN] = "(",
  [anon_sym_COMMA] = ",",
  [anon_sym_RPAREN] = ")",
  [anon_sym_COLON] = ":",
  [anon_sym_integer] = "integer",
  [anon_sym_LT] = "<",
  [anon_sym_GT] = ">",
  [anon_sym_return] = "return",
  [sym_identifier] = "identifier",
  [anon_sym_DOT] = ".",
  [sym_number] = "number",
  [anon_sym_true] = "true",
  [anon_sym_false] = "false",
  [anon_sym_PLUS] = "+",
  [anon_sym_STAR] = "*",
  [anon_sym_SLASH] = "/",
  [anon_sym_DASH] = "-",
  [sym_source_file] = "source_file",
  [sym__definition] = "_definition",
  [sym_module] = "module",
  [sym_typedef] = "typedef",
  [sym_function] = "function",
  [sym_parameter_list] = "parameter_list",
  [sym_parameter] = "parameter",
  [sym__type] = "_type",
  [sym_integer_type] = "integer_type",
  [sym_block] = "block",
  [sym__statement] = "_statement",
  [sym_return_statement] = "return_statement",
  [sym__expression] = "_expression",
  [sym_call_expression] = "call_expression",
  [sym_argument_list] = "argument_list",
  [sym_binary_expression] = "binary_expression",
  [sym_scoped_identifier] = "scoped_identifier",
  [sym_boolean] = "boolean",
  [sym_operator] = "operator",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_parameter_list_repeat1] = "parameter_list_repeat1",
  [aux_sym_block_repeat1] = "block_repeat1",
  [aux_sym_argument_list_repeat1] = "argument_list_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_mod] = anon_sym_mod,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_type] = anon_sym_type,
  [anon_sym_SEMI] = anon_sym_SEMI,
  [anon_sym_fn] = anon_sym_fn,
  [anon_sym_DASH_GT] = anon_sym_DASH_GT,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_integer] = anon_sym_integer,
  [anon_sym_LT] = anon_sym_LT,
  [anon_sym_GT] = anon_sym_GT,
  [anon_sym_return] = anon_sym_return,
  [sym_identifier] = sym_identifier,
  [anon_sym_DOT] = anon_sym_DOT,
  [sym_number] = sym_number,
  [anon_sym_true] = anon_sym_true,
  [anon_sym_false] = anon_sym_false,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [anon_sym_STAR] = anon_sym_STAR,
  [anon_sym_SLASH] = anon_sym_SLASH,
  [anon_sym_DASH] = anon_sym_DASH,
  [sym_source_file] = sym_source_file,
  [sym__definition] = sym__definition,
  [sym_module] = sym_module,
  [sym_typedef] = sym_typedef,
  [sym_function] = sym_function,
  [sym_parameter_list] = sym_parameter_list,
  [sym_parameter] = sym_parameter,
  [sym__type] = sym__type,
  [sym_integer_type] = sym_integer_type,
  [sym_block] = sym_block,
  [sym__statement] = sym__statement,
  [sym_return_statement] = sym_return_statement,
  [sym__expression] = sym__expression,
  [sym_call_expression] = sym_call_expression,
  [sym_argument_list] = sym_argument_list,
  [sym_binary_expression] = sym_binary_expression,
  [sym_scoped_identifier] = sym_scoped_identifier,
  [sym_boolean] = sym_boolean,
  [sym_operator] = sym_operator,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_parameter_list_repeat1] = aux_sym_parameter_list_repeat1,
  [aux_sym_block_repeat1] = aux_sym_block_repeat1,
  [aux_sym_argument_list_repeat1] = aux_sym_argument_list_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_mod] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_type] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SEMI] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_fn] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_integer] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_return] = {
    .visible = true,
    .named = false,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_DOT] = {
    .visible = true,
    .named = false,
  },
  [sym_number] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_true] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_false] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PLUS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SLASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH] = {
    .visible = true,
    .named = false,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym__definition] = {
    .visible = false,
    .named = true,
  },
  [sym_module] = {
    .visible = true,
    .named = true,
  },
  [sym_typedef] = {
    .visible = true,
    .named = true,
  },
  [sym_function] = {
    .visible = true,
    .named = true,
  },
  [sym_parameter_list] = {
    .visible = true,
    .named = true,
  },
  [sym_parameter] = {
    .visible = true,
    .named = true,
  },
  [sym__type] = {
    .visible = false,
    .named = true,
  },
  [sym_integer_type] = {
    .visible = true,
    .named = true,
  },
  [sym_block] = {
    .visible = true,
    .named = true,
  },
  [sym__statement] = {
    .visible = false,
    .named = true,
  },
  [sym_return_statement] = {
    .visible = true,
    .named = true,
  },
  [sym__expression] = {
    .visible = false,
    .named = true,
  },
  [sym_call_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_argument_list] = {
    .visible = true,
    .named = true,
  },
  [sym_binary_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_scoped_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_boolean] = {
    .visible = true,
    .named = true,
  },
  [sym_operator] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_parameter_list_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_block_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_argument_list_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum ts_field_identifiers {
  field_arguments = 1,
  field_body = 2,
  field_callable = 3,
  field_left = 4,
  field_name = 5,
  field_operator = 6,
  field_parameters = 7,
  field_right = 8,
  field_signed = 9,
  field_size = 10,
  field_type = 11,
  field_value = 12,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_arguments] = "arguments",
  [field_body] = "body",
  [field_callable] = "callable",
  [field_left] = "left",
  [field_name] = "name",
  [field_operator] = "operator",
  [field_parameters] = "parameters",
  [field_right] = "right",
  [field_signed] = "signed",
  [field_size] = "size",
  [field_type] = "type",
  [field_value] = "value",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 2},
  [3] = {.index = 3, .length = 2},
  [4] = {.index = 5, .length = 3},
  [5] = {.index = 8, .length = 2},
  [6] = {.index = 10, .length = 2},
  [7] = {.index = 12, .length = 2},
  [8] = {.index = 14, .length = 3},
  [9] = {.index = 17, .length = 4},
  [10] = {.index = 21, .length = 1},
  [11] = {.index = 22, .length = 3},
  [12] = {.index = 25, .length = 2},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_name, 1},
  [1] =
    {field_name, 1},
    {field_type, 2},
  [3] =
    {field_name, 1},
    {field_parameters, 2},
  [5] =
    {field_body, 3},
    {field_name, 1},
    {field_parameters, 2},
  [8] =
    {field_left, 0},
    {field_right, 2},
  [10] =
    {field_name, 0},
    {field_type, 2},
  [12] =
    {field_arguments, 1},
    {field_callable, 0},
  [14] =
    {field_name, 1},
    {field_parameters, 2},
    {field_type, 4},
  [17] =
    {field_body, 5},
    {field_name, 1},
    {field_parameters, 2},
    {field_type, 4},
  [21] =
    {field_value, 1},
  [22] =
    {field_left, 0},
    {field_operator, 1},
    {field_right, 2},
  [25] =
    {field_signed, 4},
    {field_size, 2},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 43,
  [44] = 44,
  [45] = 45,
  [46] = 46,
  [47] = 47,
  [48] = 48,
  [49] = 49,
  [50] = 50,
  [51] = 51,
  [52] = 52,
  [53] = 53,
  [54] = 54,
  [55] = 55,
  [56] = 56,
  [57] = 57,
  [58] = 58,
  [59] = 59,
  [60] = 60,
  [61] = 61,
  [62] = 62,
  [63] = 63,
  [64] = 64,
  [65] = 65,
  [66] = 66,
  [67] = 67,
  [68] = 68,
  [69] = 69,
  [70] = 70,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(27);
      ADVANCE_MAP(
        '(', 35,
        ')', 37,
        '*', 62,
        '+', 61,
        ',', 36,
        '-', 65,
        '.', 57,
        '/', 63,
        ':', 38,
        ';', 32,
        '<', 41,
        '>', 42,
        'f', 4,
        'i', 15,
        'm', 17,
        'r', 10,
        't', 19,
        '{', 29,
        '}', 30,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(58);
      END_STATE();
    case 1:
      ADVANCE_MAP(
        '(', 35,
        ')', 37,
        '*', 62,
        '+', 61,
        ',', 36,
        '-', 64,
        '.', 57,
        '/', 63,
        ';', 32,
        'r', 45,
        '{', 29,
        '}', 30,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(58);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(56);
      END_STATE();
    case 2:
      if (lookahead == ')') ADVANCE(37);
      if (lookahead == '-') ADVANCE(3);
      if (lookahead == ';') ADVANCE(32);
      if (lookahead == '{') ADVANCE(29);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(2);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(58);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(56);
      END_STATE();
    case 3:
      if (lookahead == '>') ADVANCE(34);
      END_STATE();
    case 4:
      if (lookahead == 'a') ADVANCE(14);
      if (lookahead == 'n') ADVANCE(33);
      END_STATE();
    case 5:
      if (lookahead == 'd') ADVANCE(28);
      END_STATE();
    case 6:
      if (lookahead == 'e') ADVANCE(12);
      END_STATE();
    case 7:
      if (lookahead == 'e') ADVANCE(59);
      END_STATE();
    case 8:
      if (lookahead == 'e') ADVANCE(31);
      END_STATE();
    case 9:
      if (lookahead == 'e') ADVANCE(60);
      END_STATE();
    case 10:
      if (lookahead == 'e') ADVANCE(24);
      END_STATE();
    case 11:
      if (lookahead == 'e') ADVANCE(20);
      END_STATE();
    case 12:
      if (lookahead == 'g') ADVANCE(11);
      END_STATE();
    case 13:
      if (lookahead == 'i') ADVANCE(50);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(13);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(56);
      END_STATE();
    case 14:
      if (lookahead == 'l') ADVANCE(22);
      END_STATE();
    case 15:
      if (lookahead == 'n') ADVANCE(23);
      END_STATE();
    case 16:
      if (lookahead == 'n') ADVANCE(43);
      END_STATE();
    case 17:
      if (lookahead == 'o') ADVANCE(5);
      END_STATE();
    case 18:
      if (lookahead == 'p') ADVANCE(8);
      END_STATE();
    case 19:
      if (lookahead == 'r') ADVANCE(26);
      if (lookahead == 'y') ADVANCE(18);
      END_STATE();
    case 20:
      if (lookahead == 'r') ADVANCE(39);
      END_STATE();
    case 21:
      if (lookahead == 'r') ADVANCE(16);
      END_STATE();
    case 22:
      if (lookahead == 's') ADVANCE(9);
      END_STATE();
    case 23:
      if (lookahead == 't') ADVANCE(6);
      END_STATE();
    case 24:
      if (lookahead == 't') ADVANCE(25);
      END_STATE();
    case 25:
      if (lookahead == 'u') ADVANCE(21);
      END_STATE();
    case 26:
      if (lookahead == 'u') ADVANCE(7);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(anon_sym_mod);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(anon_sym_type);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(anon_sym_fn);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(anon_sym_DASH_GT);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(anon_sym_integer);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(anon_sym_integer);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(56);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(anon_sym_LT);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(anon_sym_return);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(anon_sym_return);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(56);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(53);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(56);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(48);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(56);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(52);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(56);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'g') ADVANCE(47);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(56);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(44);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(56);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(54);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(56);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(49);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(56);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(40);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(56);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(55);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(56);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(46);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(56);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(51);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(56);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(56);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(anon_sym_DOT);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(sym_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(58);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '>') ADVANCE(34);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 1},
  [3] = {.lex_state = 1},
  [4] = {.lex_state = 1},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 1},
  [7] = {.lex_state = 1},
  [8] = {.lex_state = 1},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 1},
  [13] = {.lex_state = 1},
  [14] = {.lex_state = 1},
  [15] = {.lex_state = 1},
  [16] = {.lex_state = 1},
  [17] = {.lex_state = 1},
  [18] = {.lex_state = 1},
  [19] = {.lex_state = 1},
  [20] = {.lex_state = 2},
  [21] = {.lex_state = 2},
  [22] = {.lex_state = 2},
  [23] = {.lex_state = 2},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 13},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 13},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 13},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 0},
  [37] = {.lex_state = 1},
  [38] = {.lex_state = 2},
  [39] = {.lex_state = 0},
  [40] = {.lex_state = 1},
  [41] = {.lex_state = 1},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 2},
  [44] = {.lex_state = 0},
  [45] = {.lex_state = 2},
  [46] = {.lex_state = 0},
  [47] = {.lex_state = 0},
  [48] = {.lex_state = 0},
  [49] = {.lex_state = 2},
  [50] = {.lex_state = 0},
  [51] = {.lex_state = 0},
  [52] = {.lex_state = 2},
  [53] = {.lex_state = 0},
  [54] = {.lex_state = 0},
  [55] = {.lex_state = 2},
  [56] = {.lex_state = 0},
  [57] = {.lex_state = 2},
  [58] = {.lex_state = 0},
  [59] = {.lex_state = 0},
  [60] = {.lex_state = 0},
  [61] = {.lex_state = 0},
  [62] = {.lex_state = 0},
  [63] = {.lex_state = 0},
  [64] = {.lex_state = 2},
  [65] = {.lex_state = 0},
  [66] = {.lex_state = 0},
  [67] = {.lex_state = 2},
  [68] = {.lex_state = 2},
  [69] = {.lex_state = 2},
  [70] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_mod] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_type] = ACTIONS(1),
    [anon_sym_SEMI] = ACTIONS(1),
    [anon_sym_fn] = ACTIONS(1),
    [anon_sym_DASH_GT] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_integer] = ACTIONS(1),
    [anon_sym_LT] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [anon_sym_return] = ACTIONS(1),
    [anon_sym_DOT] = ACTIONS(1),
    [sym_number] = ACTIONS(1),
    [anon_sym_true] = ACTIONS(1),
    [anon_sym_false] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_SLASH] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(66),
    [sym__definition] = STATE(9),
    [sym_module] = STATE(9),
    [sym_typedef] = STATE(9),
    [sym_function] = STATE(9),
    [aux_sym_source_file_repeat1] = STATE(9),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_mod] = ACTIONS(5),
    [anon_sym_type] = ACTIONS(7),
    [anon_sym_fn] = ACTIONS(9),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 7,
    ACTIONS(11), 1,
      anon_sym_RBRACE,
    ACTIONS(13), 1,
      anon_sym_return,
    ACTIONS(16), 1,
      sym_identifier,
    ACTIONS(19), 1,
      sym_number,
    STATE(12), 1,
      sym_scoped_identifier,
    STATE(2), 3,
      sym__statement,
      sym_return_statement,
      aux_sym_block_repeat1,
    STATE(19), 3,
      sym__expression,
      sym_call_expression,
      sym_binary_expression,
  [26] = 7,
    ACTIONS(22), 1,
      anon_sym_RBRACE,
    ACTIONS(24), 1,
      anon_sym_return,
    ACTIONS(26), 1,
      sym_identifier,
    ACTIONS(28), 1,
      sym_number,
    STATE(12), 1,
      sym_scoped_identifier,
    STATE(4), 3,
      sym__statement,
      sym_return_statement,
      aux_sym_block_repeat1,
    STATE(19), 3,
      sym__expression,
      sym_call_expression,
      sym_binary_expression,
  [52] = 7,
    ACTIONS(24), 1,
      anon_sym_return,
    ACTIONS(26), 1,
      sym_identifier,
    ACTIONS(28), 1,
      sym_number,
    ACTIONS(30), 1,
      anon_sym_RBRACE,
    STATE(12), 1,
      sym_scoped_identifier,
    STATE(2), 3,
      sym__statement,
      sym_return_statement,
      aux_sym_block_repeat1,
    STATE(19), 3,
      sym__expression,
      sym_call_expression,
      sym_binary_expression,
  [78] = 5,
    ACTIONS(34), 1,
      anon_sym_mod,
    ACTIONS(37), 1,
      anon_sym_type,
    ACTIONS(40), 1,
      anon_sym_fn,
    ACTIONS(32), 2,
      ts_builtin_sym_end,
      anon_sym_RBRACE,
    STATE(5), 5,
      sym__definition,
      sym_module,
      sym_typedef,
      sym_function,
      aux_sym_source_file_repeat1,
  [99] = 1,
    ACTIONS(43), 10,
      anon_sym_LBRACE,
      anon_sym_SEMI,
      anon_sym_LPAREN,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_DOT,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_DASH,
  [112] = 3,
    STATE(15), 1,
      sym_argument_list,
    STATE(23), 1,
      sym_operator,
    ACTIONS(45), 8,
      anon_sym_SEMI,
      anon_sym_LPAREN,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_DASH,
  [129] = 7,
    ACTIONS(47), 1,
      anon_sym_LPAREN,
    ACTIONS(49), 1,
      anon_sym_COMMA,
    ACTIONS(51), 1,
      anon_sym_RPAREN,
    STATE(15), 1,
      sym_argument_list,
    STATE(23), 1,
      sym_operator,
    STATE(50), 1,
      aux_sym_argument_list_repeat1,
    ACTIONS(53), 4,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_DASH,
  [154] = 5,
    ACTIONS(5), 1,
      anon_sym_mod,
    ACTIONS(7), 1,
      anon_sym_type,
    ACTIONS(9), 1,
      anon_sym_fn,
    ACTIONS(55), 1,
      ts_builtin_sym_end,
    STATE(5), 5,
      sym__definition,
      sym_module,
      sym_typedef,
      sym_function,
      aux_sym_source_file_repeat1,
  [174] = 5,
    ACTIONS(5), 1,
      anon_sym_mod,
    ACTIONS(7), 1,
      anon_sym_type,
    ACTIONS(9), 1,
      anon_sym_fn,
    ACTIONS(57), 1,
      anon_sym_RBRACE,
    STATE(11), 5,
      sym__definition,
      sym_module,
      sym_typedef,
      sym_function,
      aux_sym_source_file_repeat1,
  [194] = 5,
    ACTIONS(5), 1,
      anon_sym_mod,
    ACTIONS(7), 1,
      anon_sym_type,
    ACTIONS(9), 1,
      anon_sym_fn,
    ACTIONS(59), 1,
      anon_sym_RBRACE,
    STATE(5), 5,
      sym__definition,
      sym_module,
      sym_typedef,
      sym_function,
      aux_sym_source_file_repeat1,
  [214] = 2,
    ACTIONS(63), 1,
      anon_sym_DOT,
    ACTIONS(61), 8,
      anon_sym_SEMI,
      anon_sym_LPAREN,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_DASH,
  [228] = 5,
    ACTIONS(47), 1,
      anon_sym_LPAREN,
    STATE(15), 1,
      sym_argument_list,
    STATE(23), 1,
      sym_operator,
    ACTIONS(65), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
    ACTIONS(53), 4,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_DASH,
  [248] = 1,
    ACTIONS(67), 8,
      anon_sym_SEMI,
      anon_sym_LPAREN,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_DASH,
  [259] = 1,
    ACTIONS(69), 8,
      anon_sym_SEMI,
      anon_sym_LPAREN,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_DASH,
  [270] = 5,
    ACTIONS(47), 1,
      anon_sym_LPAREN,
    ACTIONS(71), 1,
      anon_sym_SEMI,
    STATE(15), 1,
      sym_argument_list,
    STATE(23), 1,
      sym_operator,
    ACTIONS(53), 4,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_DASH,
  [289] = 1,
    ACTIONS(73), 8,
      anon_sym_SEMI,
      anon_sym_LPAREN,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_DASH,
  [300] = 1,
    ACTIONS(75), 8,
      anon_sym_SEMI,
      anon_sym_LPAREN,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_DASH,
  [311] = 5,
    ACTIONS(47), 1,
      anon_sym_LPAREN,
    ACTIONS(77), 1,
      anon_sym_SEMI,
    STATE(15), 1,
      sym_argument_list,
    STATE(23), 1,
      sym_operator,
    ACTIONS(53), 4,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_DASH,
  [330] = 5,
    ACTIONS(79), 1,
      anon_sym_RPAREN,
    ACTIONS(81), 1,
      sym_identifier,
    ACTIONS(83), 1,
      sym_number,
    STATE(12), 1,
      sym_scoped_identifier,
    STATE(8), 3,
      sym__expression,
      sym_call_expression,
      sym_binary_expression,
  [348] = 5,
    ACTIONS(81), 1,
      sym_identifier,
    ACTIONS(85), 1,
      anon_sym_SEMI,
    ACTIONS(87), 1,
      sym_number,
    STATE(12), 1,
      sym_scoped_identifier,
    STATE(16), 3,
      sym__expression,
      sym_call_expression,
      sym_binary_expression,
  [366] = 4,
    ACTIONS(81), 1,
      sym_identifier,
    ACTIONS(89), 1,
      sym_number,
    STATE(12), 1,
      sym_scoped_identifier,
    STATE(13), 3,
      sym__expression,
      sym_call_expression,
      sym_binary_expression,
  [381] = 4,
    ACTIONS(81), 1,
      sym_identifier,
    ACTIONS(91), 1,
      sym_number,
    STATE(12), 1,
      sym_scoped_identifier,
    STATE(7), 3,
      sym__expression,
      sym_call_expression,
      sym_binary_expression,
  [396] = 1,
    ACTIONS(93), 5,
      ts_builtin_sym_end,
      anon_sym_mod,
      anon_sym_RBRACE,
      anon_sym_type,
      anon_sym_fn,
  [404] = 1,
    ACTIONS(95), 5,
      ts_builtin_sym_end,
      anon_sym_mod,
      anon_sym_RBRACE,
      anon_sym_type,
      anon_sym_fn,
  [412] = 4,
    ACTIONS(97), 1,
      anon_sym_integer,
    ACTIONS(99), 1,
      sym_identifier,
    STATE(34), 1,
      sym_scoped_identifier,
    STATE(70), 2,
      sym__type,
      sym_integer_type,
  [426] = 1,
    ACTIONS(101), 5,
      ts_builtin_sym_end,
      anon_sym_mod,
      anon_sym_RBRACE,
      anon_sym_type,
      anon_sym_fn,
  [434] = 4,
    ACTIONS(97), 1,
      anon_sym_integer,
    ACTIONS(99), 1,
      sym_identifier,
    STATE(34), 1,
      sym_scoped_identifier,
    STATE(48), 2,
      sym__type,
      sym_integer_type,
  [448] = 1,
    ACTIONS(103), 5,
      ts_builtin_sym_end,
      anon_sym_mod,
      anon_sym_RBRACE,
      anon_sym_type,
      anon_sym_fn,
  [456] = 1,
    ACTIONS(105), 5,
      ts_builtin_sym_end,
      anon_sym_mod,
      anon_sym_RBRACE,
      anon_sym_type,
      anon_sym_fn,
  [464] = 1,
    ACTIONS(107), 5,
      ts_builtin_sym_end,
      anon_sym_mod,
      anon_sym_RBRACE,
      anon_sym_type,
      anon_sym_fn,
  [472] = 4,
    ACTIONS(97), 1,
      anon_sym_integer,
    ACTIONS(99), 1,
      sym_identifier,
    STATE(34), 1,
      sym_scoped_identifier,
    STATE(53), 2,
      sym__type,
      sym_integer_type,
  [486] = 1,
    ACTIONS(109), 5,
      ts_builtin_sym_end,
      anon_sym_mod,
      anon_sym_RBRACE,
      anon_sym_type,
      anon_sym_fn,
  [494] = 2,
    ACTIONS(63), 1,
      anon_sym_DOT,
    ACTIONS(111), 4,
      anon_sym_LBRACE,
      anon_sym_SEMI,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [504] = 1,
    ACTIONS(113), 5,
      ts_builtin_sym_end,
      anon_sym_mod,
      anon_sym_RBRACE,
      anon_sym_type,
      anon_sym_fn,
  [512] = 1,
    ACTIONS(115), 5,
      ts_builtin_sym_end,
      anon_sym_mod,
      anon_sym_RBRACE,
      anon_sym_type,
      anon_sym_fn,
  [520] = 2,
    ACTIONS(117), 2,
      anon_sym_RBRACE,
      sym_number,
    ACTIONS(119), 2,
      anon_sym_return,
      sym_identifier,
  [529] = 4,
    ACTIONS(121), 1,
      anon_sym_LBRACE,
    ACTIONS(123), 1,
      anon_sym_SEMI,
    ACTIONS(125), 1,
      anon_sym_DASH_GT,
    STATE(29), 1,
      sym_block,
  [542] = 1,
    ACTIONS(127), 4,
      anon_sym_LBRACE,
      anon_sym_SEMI,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [549] = 2,
    ACTIONS(129), 2,
      anon_sym_RBRACE,
      sym_number,
    ACTIONS(131), 2,
      anon_sym_return,
      sym_identifier,
  [558] = 2,
    ACTIONS(133), 2,
      anon_sym_RBRACE,
      sym_number,
    ACTIONS(135), 2,
      anon_sym_return,
      sym_identifier,
  [567] = 3,
    ACTIONS(137), 1,
      anon_sym_COMMA,
    ACTIONS(139), 1,
      anon_sym_RPAREN,
    STATE(51), 1,
      aux_sym_parameter_list_repeat1,
  [577] = 1,
    ACTIONS(141), 3,
      anon_sym_LBRACE,
      anon_sym_SEMI,
      anon_sym_DASH_GT,
  [583] = 2,
    STATE(59), 1,
      sym_boolean,
    ACTIONS(143), 2,
      anon_sym_true,
      anon_sym_false,
  [591] = 1,
    ACTIONS(145), 3,
      anon_sym_LBRACE,
      anon_sym_SEMI,
      anon_sym_DASH_GT,
  [597] = 3,
    ACTIONS(147), 1,
      anon_sym_COMMA,
    ACTIONS(150), 1,
      anon_sym_RPAREN,
    STATE(46), 1,
      aux_sym_parameter_list_repeat1,
  [607] = 3,
    ACTIONS(65), 1,
      anon_sym_RPAREN,
    ACTIONS(152), 1,
      anon_sym_COMMA,
    STATE(47), 1,
      aux_sym_argument_list_repeat1,
  [617] = 3,
    ACTIONS(121), 1,
      anon_sym_LBRACE,
    ACTIONS(155), 1,
      anon_sym_SEMI,
    STATE(31), 1,
      sym_block,
  [627] = 3,
    ACTIONS(157), 1,
      anon_sym_RPAREN,
    ACTIONS(159), 1,
      sym_identifier,
    STATE(42), 1,
      sym_parameter,
  [637] = 3,
    ACTIONS(49), 1,
      anon_sym_COMMA,
    ACTIONS(161), 1,
      anon_sym_RPAREN,
    STATE(47), 1,
      aux_sym_argument_list_repeat1,
  [647] = 3,
    ACTIONS(137), 1,
      anon_sym_COMMA,
    ACTIONS(163), 1,
      anon_sym_RPAREN,
    STATE(46), 1,
      aux_sym_parameter_list_repeat1,
  [657] = 1,
    ACTIONS(165), 3,
      anon_sym_LBRACE,
      anon_sym_SEMI,
      anon_sym_DASH_GT,
  [663] = 1,
    ACTIONS(167), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [668] = 1,
    ACTIONS(150), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [673] = 1,
    ACTIONS(169), 2,
      sym_identifier,
      sym_number,
  [678] = 2,
    ACTIONS(171), 1,
      anon_sym_LPAREN,
    STATE(38), 1,
      sym_parameter_list,
  [685] = 2,
    ACTIONS(159), 1,
      sym_identifier,
    STATE(54), 1,
      sym_parameter,
  [692] = 1,
    ACTIONS(173), 1,
      sym_number,
  [696] = 1,
    ACTIONS(175), 1,
      anon_sym_GT,
  [700] = 1,
    ACTIONS(177), 1,
      anon_sym_COLON,
  [704] = 1,
    ACTIONS(179), 1,
      anon_sym_LT,
  [708] = 1,
    ACTIONS(181), 1,
      anon_sym_GT,
  [712] = 1,
    ACTIONS(183), 1,
      anon_sym_COMMA,
  [716] = 1,
    ACTIONS(185), 1,
      sym_identifier,
  [720] = 1,
    ACTIONS(187), 1,
      anon_sym_LBRACE,
  [724] = 1,
    ACTIONS(189), 1,
      ts_builtin_sym_end,
  [728] = 1,
    ACTIONS(191), 1,
      sym_identifier,
  [732] = 1,
    ACTIONS(193), 1,
      sym_identifier,
  [736] = 1,
    ACTIONS(195), 1,
      sym_identifier,
  [740] = 1,
    ACTIONS(197), 1,
      anon_sym_SEMI,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 26,
  [SMALL_STATE(4)] = 52,
  [SMALL_STATE(5)] = 78,
  [SMALL_STATE(6)] = 99,
  [SMALL_STATE(7)] = 112,
  [SMALL_STATE(8)] = 129,
  [SMALL_STATE(9)] = 154,
  [SMALL_STATE(10)] = 174,
  [SMALL_STATE(11)] = 194,
  [SMALL_STATE(12)] = 214,
  [SMALL_STATE(13)] = 228,
  [SMALL_STATE(14)] = 248,
  [SMALL_STATE(15)] = 259,
  [SMALL_STATE(16)] = 270,
  [SMALL_STATE(17)] = 289,
  [SMALL_STATE(18)] = 300,
  [SMALL_STATE(19)] = 311,
  [SMALL_STATE(20)] = 330,
  [SMALL_STATE(21)] = 348,
  [SMALL_STATE(22)] = 366,
  [SMALL_STATE(23)] = 381,
  [SMALL_STATE(24)] = 396,
  [SMALL_STATE(25)] = 404,
  [SMALL_STATE(26)] = 412,
  [SMALL_STATE(27)] = 426,
  [SMALL_STATE(28)] = 434,
  [SMALL_STATE(29)] = 448,
  [SMALL_STATE(30)] = 456,
  [SMALL_STATE(31)] = 464,
  [SMALL_STATE(32)] = 472,
  [SMALL_STATE(33)] = 486,
  [SMALL_STATE(34)] = 494,
  [SMALL_STATE(35)] = 504,
  [SMALL_STATE(36)] = 512,
  [SMALL_STATE(37)] = 520,
  [SMALL_STATE(38)] = 529,
  [SMALL_STATE(39)] = 542,
  [SMALL_STATE(40)] = 549,
  [SMALL_STATE(41)] = 558,
  [SMALL_STATE(42)] = 567,
  [SMALL_STATE(43)] = 577,
  [SMALL_STATE(44)] = 583,
  [SMALL_STATE(45)] = 591,
  [SMALL_STATE(46)] = 597,
  [SMALL_STATE(47)] = 607,
  [SMALL_STATE(48)] = 617,
  [SMALL_STATE(49)] = 627,
  [SMALL_STATE(50)] = 637,
  [SMALL_STATE(51)] = 647,
  [SMALL_STATE(52)] = 657,
  [SMALL_STATE(53)] = 663,
  [SMALL_STATE(54)] = 668,
  [SMALL_STATE(55)] = 673,
  [SMALL_STATE(56)] = 678,
  [SMALL_STATE(57)] = 685,
  [SMALL_STATE(58)] = 692,
  [SMALL_STATE(59)] = 696,
  [SMALL_STATE(60)] = 700,
  [SMALL_STATE(61)] = 704,
  [SMALL_STATE(62)] = 708,
  [SMALL_STATE(63)] = 712,
  [SMALL_STATE(64)] = 716,
  [SMALL_STATE(65)] = 720,
  [SMALL_STATE(66)] = 724,
  [SMALL_STATE(67)] = 728,
  [SMALL_STATE(68)] = 732,
  [SMALL_STATE(69)] = 736,
  [SMALL_STATE(70)] = 740,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [11] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_block_repeat1, 2, 0, 0),
  [13] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_repeat1, 2, 0, 0), SHIFT_REPEAT(21),
  [16] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_repeat1, 2, 0, 0), SHIFT_REPEAT(12),
  [19] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_block_repeat1, 2, 0, 0), SHIFT_REPEAT(19),
  [22] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [24] = {.entry = {.count = 1, .reusable = false}}, SHIFT(21),
  [26] = {.entry = {.count = 1, .reusable = false}}, SHIFT(12),
  [28] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [30] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [32] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [34] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(67),
  [37] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(69),
  [40] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(68),
  [43] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scoped_identifier, 3, 0, 5),
  [45] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_binary_expression, 3, 0, 11),
  [47] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [49] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [51] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [53] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [55] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [57] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [59] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [61] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__expression, 1, 0, 0),
  [63] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [65] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_argument_list_repeat1, 2, 0, 0),
  [67] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_argument_list, 2, 0, 0),
  [69] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_call_expression, 2, 0, 7),
  [71] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [73] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_argument_list, 4, 0, 0),
  [75] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_argument_list, 3, 0, 0),
  [77] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [79] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [81] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [83] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [85] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [87] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [89] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [91] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [93] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_module, 4, 0, 1),
  [95] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_typedef, 4, 0, 2),
  [97] = {.entry = {.count = 1, .reusable = false}}, SHIFT(61),
  [99] = {.entry = {.count = 1, .reusable = false}}, SHIFT(34),
  [101] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function, 4, 0, 3),
  [103] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function, 4, 0, 4),
  [105] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_module, 5, 0, 1),
  [107] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function, 6, 0, 9),
  [109] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function, 6, 0, 8),
  [111] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__type, 1, 0, 0),
  [113] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 3, 0, 0),
  [115] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 2, 0, 0),
  [117] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_return_statement, 2, 0, 0),
  [119] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_return_statement, 2, 0, 0),
  [121] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [123] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [125] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [127] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_integer_type, 6, 0, 12),
  [129] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_return_statement, 3, 0, 10),
  [131] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_return_statement, 3, 0, 10),
  [133] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__statement, 2, 0, 0),
  [135] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__statement, 2, 0, 0),
  [137] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [139] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [141] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter_list, 2, 0, 0),
  [143] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [145] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter_list, 4, 0, 0),
  [147] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_parameter_list_repeat1, 2, 0, 0), SHIFT_REPEAT(57),
  [150] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_parameter_list_repeat1, 2, 0, 0),
  [152] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_argument_list_repeat1, 2, 0, 0), SHIFT_REPEAT(22),
  [155] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [157] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [159] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [161] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [163] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [165] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter_list, 3, 0, 0),
  [167] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter, 3, 0, 6),
  [169] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_operator, 1, 0, 0),
  [171] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [173] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [175] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [177] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [179] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [181] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_boolean, 1, 0, 0),
  [183] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [185] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [187] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [189] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [191] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [193] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [195] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [197] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_rf(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
