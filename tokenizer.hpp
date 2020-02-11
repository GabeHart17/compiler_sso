#ifndef TOKENIZER_HEADER
#define TOKENIZER_HEADER

#include "token.hpp"
#include "regex_tokenizer.hpp"
#include "create_tokenizer.hpp"
#include <vector>
#include <utility>
#include <string>
#include <regex>


class Tokenizer {
private:
  RegexTokenizer* rt_;
  std::vector<Token> first_pass(std::string);
  std::vector<Token> second_pass(const std::vector<Token>&);
  static std::string strip_(const std::string& s) {
    std::string whitespace = " \f\n\r\t\v";
    size_t f = s.find_first_not_of(whitespace);
    size_t l = s.find_last_not_of(whitespace);
    unsigned int len = l - f + 1;
    return s.substr(f, len);
  }

public:
  Tokenizer ();
  ~Tokenizer ();
  std::vector<Token> operator()(std::string);
};


Tokenizer::Tokenizer() {
  rt_ = create_tokenizer();
}


Tokenizer::~Tokenizer() {
  delete rt_;
}


std::vector<Token> Tokenizer::first_pass(std::string str) {
  std::vector<Token> tokens;
  Token t;
  size_t pos = 0;
  while (pos < str.length()){
    t = rt_ -> get_token(str.substr(pos));
    tokens.push_back(t);
    pos += t.get_lexeme().length();
  }
  return tokens;
}


std::vector<Token> Tokenizer::second_pass(const std::vector<Token>& first_res) {
  std::vector<Token> second_res;
  second_res.reserve(first_res.size());

  if (first_res.size() > 0) {
    Token current;
    for (size_t i = 0; i < first_res.size(); i++) {
      current = first_res[i];
      std::string l = strip_(current.get_lexeme());
      Token t(current.get_type(), l);

      if (l == "*") {
        if (i == 0) {
          t = Token(TokenType::t_dereference, l);
        } else if (second_res.back().is_type()) {
          t = Token(TokenType::t_pointer, second_res.back().get_lexeme() + "*");
          second_res.pop_back();
        } else if (second_res.back().is_numeric_literal() ||
                   second_res.back().get_type() == TokenType::t_paren_right  ||
                   second_res.back().get_type() == TokenType::t_bracket_right ||
                   second_res.back().get_type() == TokenType::t_ident) {
         t = Token(TokenType::t_multiply, "*");
        } else {
         t = Token(TokenType::t_dereference, "*");
        }
      }

      if (current.get_type() == TokenType::t_paren_right) {
        if (second_res.size() >= 2) {
          if (second_res.back().is_type() &&
              (second_res.end() - 2)->get_type() == TokenType::t_paren_left) {
            t = Token(TokenType::t_cast,
                      "(" + second_res.back().get_lexeme() + ")");
            second_res.pop_back();
            second_res.pop_back();  // yes, this is supposed to happen twice
          }
        }
      }

      if (l == "&") {
        if (i == 0) {
          t = Token(TokenType::t_reference, "&");
        } else if (second_res.back().is_numeric_literal() ||
                   second_res.back().get_type() == TokenType::t_literal_string ||
                   second_res.back().get_type() == TokenType::t_paren_right  ||
                   second_res.back().get_type() == TokenType::t_bracket_right ||
                   second_res.back().get_type() == TokenType::t_ident) {
         t = Token(TokenType::t_bitwise_and, "&");
       } else {
         t = Token(TokenType::t_reference, "&");
       }
      }

      second_res.push_back(t);
    }
  }

  return second_res;
}


std::vector<Token> Tokenizer::operator()(std::string str) {
  return second_pass(first_pass(str));
}


#endif
