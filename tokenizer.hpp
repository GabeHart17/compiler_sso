#ifndef TOKENIZER_HEADER
#define TOKENIZER_HEADER

#include "token.hpp"
#include "regex_tokenizer.hpp"
#include "create_tokenizer.hpp"
#include <vector>
#include <utility>
#include <string>


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
  return first_res;
}


std::vector<Token> Tokenizer::tokenize(std::string str) {
  return second_pass(first_pass(str));
}


#endif
