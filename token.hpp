#ifndef TOKEN_HEADER
#define TOKEN_HEADER

#include <string>

enum class TokenType {
  // used for invalid/empty tokens
  t_null = 0,

  // generic, unassigned token type. Temporarily assigned to contextful tokens
  t_generic,

  // end of file
  t_eof,

  // formatting and blocks
  t_semicolon = 100,
  t_curly_left,
  t_curly_right,
  t_paren_left,
  t_paren_right,
  t_coma,

  //reserved keywords
  t_if = 200,
  t_else,
  t_while,
  t_for,
  t_break,
  t_continue,
  t_return,

  // type names
  t_bool = 300,
  t_char,
  t_int,
  t_float,
  t_pointer,  // 19

  // identifiers
  t_ident,

  // literals
  t_literal_bool = 400,
  t_literal_char,
  t_literal_string,
  t_literal_int,
  t_literal_float,

  // partial literals. needed for first pass, but will never appear in output
  t_literal_char_start,  // excludes closing '
  t_literal_string_start,  // excludes closing "

  // variable declaration and assignment
  t_array, // []
  t_assign,
  t_bracket_left,
  t_bracket_right,

  // binary operators
  t_plus = 500,
  t_minus,
  t_multiply,
  t_divide,
  t_modulo,
  t_equal,
  t_not_equal,
  t_greater_than,
  t_less_than,
  t_gt_or_eq,
  t_lt_or_eq,
  t_and,
  t_or,
  t_bitwise_and,
  t_bitwise_or,

  // unary operators
  t_not = 600,
  t_bitwise_not,
  t_reference,
  t_dereference,
  t_increment,
  t_decrement,
  t_cast,


  // nonterminals
  epsilon = 1000,
  PROGRAM,
  FUNCTION,
  VAR_DECL,
  F_DECL_ARGS,
  ARG_DECLS,
  BLOCK,
  STATEMENTS,
  STATEMENT,
  EXPR,
  E0, // 1010
  E1,
  E2,
  E3,
  E4,
  E5,
  E6,
  E7,
  E8,
  E9,
  E10, // 1020
  E11,
  E12,
  U1,
  B2,
  B3,
  B5,
  B6,
  CONDITION,
  ELSE_BLOCKS,
  FUNCTION_CALL, // 1030
  CALL_ARGS,
  LOOP,
  FOR_LOOP,
  FOR_STATEMENT,
  FOR_CONDITION,
  WHILE_LOOP,
  TYPE_NAME,
  L_VALUE,
  R_VALUE,
  LITERAL
};

bool is_terminal(TokenType n) {
  return (int) n < 1000;
}


class Token {
private:
  TokenType type_;
  std::string lexeme_;

public:
  Token() : type_(TokenType::t_null), lexeme_("") {}
  Token(TokenType t) : type_(t), lexeme_("") {}
  Token (TokenType t, std::string l) : type_(t), lexeme_(l) {}
  ~Token () {}

  TokenType get_type() const {
    return type_;
  }

  std::string get_lexeme() const {
    return lexeme_;
  }

  bool is_type() const {  // if this token names a type
    return type_ == TokenType::t_char ||
           type_ == TokenType::t_float ||
           type_ == TokenType::t_int ||
           type_ == TokenType::t_pointer;
  }

  bool is_numeric_literal() const {
    return type_ == TokenType::t_literal_int ||
           type_ == TokenType::t_literal_bool ||
           type_ == TokenType::t_literal_char ||
           type_ == TokenType::t_literal_float;
  }

  bool is_terminal() const {
    return (int) type_ < 1000;
  }
};



#endif
