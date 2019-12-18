#include "tokenizer.hpp"
#include "token.hpp"
#include <string>
#include <vector>
#include <utility>
#include <regex>


#ifndef CREATE_TOKENIZER_HEADER
#define CREATE_TOKENIZER_HEADER


RegexTokenizer* make_tokenizer() {
  std::vector<token_regex> vec();
  const std::string keywords[] {
    "if",
    "else",
    "for",
    "while",
    "break",
    "continue",
    "return"
  };
  const TokenType keyword_tokens[] {
    TokenType::t_if,
    TokenType::t_else,
    TokenType::t_for,
    TokenType::t_while,
    TokenType::t_break,
    TokenType::t_continue,
    TokenType::t_return
  };
  const std::string types[] {
    "char",
    "int",
    "float"
  };
  const TokenType type_tokens[] {
    TokenType::t_char,
    TokenType::t_int,
    TokenType::t_float
  };
  const std::string operators[] {
    "=",
    "==",
    "!=",
    ">=",
    "<=",
    ">",
    "<",
    "!",
    "\\|",
    "&",
    "&&",
    "\\*",
    "/",
    "\\+",
    "-"
  };
  const TokenType operator_tokens[] {
    TokenType::t_assign,
    TokenType::t_equal,
    TokenType::t_not_equal,
    TokenType::t_gt_or_eq,
    TokenType::t_lt_or_eq,
    TokenType::t_greater_than,
    TokenType::t_less_than,
    TokenType::t_not,
    TokenType::t_bitwise_or,
    TokenType::generic,
    TokenType::t_and,
    TokenType::t_generic,
    TokenType::t_divide,
    TokenType::t_plus,
    TokenType::t_minus
  };
  const std::string control[] {
    "\\{",
    "\\}",
    "\\(",
    "\\)",
    "\\[",
    "\\]",
    ",",
    ";"
  };
  const TokenType control_tokens[] {
    TokenType::t_curly_left,
    TokenType::t_curly_right,
    TokenType::t_paren_left,
    TokenType::t_paren_right,
    TokenType::t_bracket_left,
    TokenType::t_bracket_right,
    TokenType::t_coma,
    TokenType::t_semicolon;
  };

  for (size_t i = 0; i < 7; i++) {
    vec.push_back(token_regex(keyword_tokens[i], std::regex(keywords[i])));
  }

  for (size_t i = 0; i < 3; i++) {
    vec.push_back(token_regex(type_tokens[i], std::regex(types[i])));
  }

  for (size_t i = 0; i < 15; i++) {
    vec.push_back(token_regex(operator_tokens[i], std::regex(operators[i])));
  }

  for (size_t i = 0; i < 8; i++) {
    vec.push_back(token_regex(control[i], std::regex(control_tokens[i])));
  }

  // string literals
  vec.push_back(token_regex(TokenType::t_literal_string, "\".*\""));

  // char literals
  vec.push_back(token_regex(TokenType::t_literal_char, "'.'"));

  // int literals
  vec.push_back(token_regex(TokenType::t_literal_int, "\\d+"));

  // float literals
  vec.push_back(token_regex(TokenType::t_literal_float, "\d+\.\d+")));

  // identifiers
  vec.push_back(token_regex(TokenType::t_ident, "\\w(\\w|\d)*"));

  RegexTokenizer* rt = new RegexTokenizer(vec);
  return rt;
}


#endif