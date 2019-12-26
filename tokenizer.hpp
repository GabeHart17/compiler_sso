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
  std::vector<Token> second_res;
  second_res.reserve(first_res.size());

  Token context;
  Token current;
  if (first_res.size() > 0) {
    Token t(first_res[0].get_type(), strip_(first_res[0].get_lexeme()));
    second_res.push_back(t);
  }

  for (size_t i = 1; i < first_res.size(); i++) {
    context = second_res[i - 1];
    current = first_res[i];
    std::string l = strip_(current.get_lexeme());



    Token t(current.get_type(), l);
    second_res.push_back(t);
  }

  return second_res;
}


std::vector<Token> Tokenizer::tokenize(std::string str) {
  return second_pass(first_pass(str));
}


#endif
