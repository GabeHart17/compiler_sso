#include <string>


#ifndef TOKEN_HEADER
#define TOKEN_HEADER 1


namespace cmpl {
  enum class TokType {
    t_if,
    t_else,
    t_while,
    t_for,
    t_break,
    t_continue,
    t_return,

    t_ident,
    t_literal,

    t_type,
    t_array, // []
    t_assign,

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
