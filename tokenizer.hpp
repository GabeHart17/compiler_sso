#include "token.hpp"
#include "regex_tokenizer.hpp"
#include "create_tokenizer.hpp"
#include <vector>
#include <pair>
#include <string>



#ifndef TOKENIZER_HEADER
#define TOKENIZER_HEADER


class Tokenizer {
private:
  RegexTokenizer* rt_;
  std::vector<Token> first_pass(std::string);
  void second_pass(std::vector<Token>&);

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


#endif
