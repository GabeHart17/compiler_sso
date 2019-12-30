#ifndef CREATE_TOKENIZER_HEADER
#define CREATE_TOKENIZER_HEADER

#include "tokenizer.hpp"
#include "token.hpp"
#include <string>
#include <vector>
#include <utility>
#include <regex>



RegexTokenizer* create_tokenizer() {
  std::vector<token_regex> vec;
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
    "bool",
    "char",
    "int",
    "float"
  };
  const TokenType type_tokens[] {
    TokenType::t_bool,
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
    "-",
    "\\+\\+",
    "--"
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
    TokenType::t_generic,
    TokenType::t_and,
    TokenType::t_generic,
    TokenType::t_divide,
    TokenType::t_plus,
    TokenType::t_minus,
    TokenType::t_increment,
    TokenType::t_decrement
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
    TokenType::t_semicolon
  };

  for (size_t i = 0; i < 7; i++) {
    vec.push_back(token_regex(keyword_tokens[i], std::regex("\\s*" + keywords[i] + "\\s*")));
  }

  for (size_t i = 0; i < 3; i++) {
    vec.push_back(token_regex(type_tokens[i], std::regex("\\s*" + types[i] + "\\s*")));
  }

  for (size_t i = 0; i < 17; i++) {
    vec.push_back(token_regex(operator_tokens[i], std::regex("\\s*" + operators[i] + "\\s*")));
  }

  for (size_t i = 0; i < 8; i++) {
    vec.push_back(token_regex(control_tokens[i], std::regex("\\s*" + control[i] + "\\s*")));
  }

  // bool literals
  vec.push_back(token_regex(TokenType::t_literal_bool, "\\s*(true)|(false)\\s*"));

  // string literals
  vec.push_back(token_regex(TokenType::t_literal_string, "\\s*\"([^\\\\\"]|(\\\\[\\\\\"abfnrtv]))*\"\\s*"));
  vec.push_back(token_regex(TokenType::t_literal_string_start, "\\s*\"([^\"]|(\\\\[\\\\\"abfnrtv]))*"));

  // char literals
  vec.push_back(token_regex(TokenType::t_literal_char, "\\s*'([^\\\\']|(\\\\[\\\\\'abfnrtv]))'\\s*"));
  vec.push_back(token_regex(TokenType::t_literal_char_start, "\\s*'([^']|(\\\\[\\\\\'abfnrtv]))?"));

  // int literals
  vec.push_back(token_regex(TokenType::t_literal_int, "\\s*\\d+\\s*"));

  // float literals
  vec.push_back(token_regex(TokenType::t_literal_float, "\\s*(\\d*\\.\\d+)|\\d+\\.\\s*"));

  // identifiers
  vec.push_back(token_regex(TokenType::t_ident, "\\s*\\w(\\w|\\d)*\\s*"));

  RegexTokenizer* rt = new RegexTokenizer(vec);
  return rt;
}


#endif
