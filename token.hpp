#include <string>


#ifndef TOKEN_HEADER
#define TOKEN_HEADER 1


namespace cmpl {
  enum class TokType {
    // used as value of fsm states that do not represent a valid token
    t_null,

    // generic, unassigned token type. Temporarily assigned to contextful tokens
    t_generic,

    // formatting and blocks
    t_semicolon,
    t_curly_left,
    t_curly_right,

    //reserved keywords
    t_if,
    t_else,
    t_while,
    t_for,
    t_break,
    t_continue,
    t_return,

    // variables
    t_ident,
    t_literal_char,
    t_literal_string,
    t_literal_int,
    t_literal_float,

    // variable declaration and assignment
    t_type,
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
    t_dereference
  };


  class Token {
  private:
    TokType type;
    std::string lexeme;

  public:
    Token (TokType t, std::string l) {
      type = t;
      lexeme = l;
    }
    ~Token ();

    TokType type() {
      return type;
    }

    std::string lexeme() {
      return lexeme;
    }
  };
} /* cmpl */


#endif
