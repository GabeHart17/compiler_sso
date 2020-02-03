#ifndef TOKEN_HEADER
#define TOKEN_HEADER

#include <string>

enum class TokenType {
  // used for invalid tokens
  t_null,

  // generic, unassigned token type. Temporarily assigned to contextful tokens
  t_generic,

  // formatting and blocks
  t_semicolon,
  t_curly_left,
  t_curly_right,
  t_paren_left,
  t_paren_right,
  t_coma,

  //reserved keywords
  t_if,
  t_else,
  t_while,
  t_for,
  t_break,
  t_continue,
  t_return,

  // type names
  t_bool,
  t_char,
  t_int,
  t_float,
  t_pointer,  // fix later, generic pointer type

  // identifiers
  t_ident,

  // literals
  t_literal_bool,
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
  t_plus,
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
  t_not,
  t_bitwise_not,
  t_reference,
  t_dereference,
  t_increment,
  t_decrement,
  t_cast,


  // nonterminals
  PROGRAM = 1000,
  BLOCK,
  EXPR,
  STMT,
  STMTS,
  CONDITION,
  ELSE_BLOCKS,
  // TODO: finish
};

bool is_terminal(TokenType n) {
  return (int) n < 1000;
}


class Token {
private:
  TokenType type_;
  std::string lexeme_;

public:
  Token() : type_(TokenType::t_generic), lexeme_("") {}
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
