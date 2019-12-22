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

public:
  Tokenizer ();
  ~Tokenizer ();
  std::vector<Token> tokenize(std::string);
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
  /*
  std::vector<Token> second_res;
  Token context;
  for (Token t : first_res) {
    if (t.get_type() == TokenType::t_generic) {
      if (std::regex_match(t.get_lexeme(), std::regex("\\s*\\*\\s*"))) {
        if (context == TokenType::t_ident ||
            context == TokenType::t_paren_right ||
            context == TokenType::t_bracket_right) {
              second_res.push_back(Token(TokenType::t_multiply, "*"));
            }
      }
    }
  }
  */
  return first_res;
}


std::vector<Token> Tokenizer::tokenize(std::string str) {
  return second_pass(first_pass(str));
}


#endif
