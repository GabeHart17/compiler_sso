#include "token.hpp"
#include <vector>
#include <utility>
#include <regex>
#include <string>


#ifndef REGEX_TOKENIZER_HEADER
#define REGEX_TOKENIZER_HEADER


typedef token_regex std::pair<TokenType, std::regex>;


class RegexTokenizer {
private:
   std::vector<token_regex> regexes_;

public:
  RegexTokenizer();
  RegexTokenizer(std::vector<token_regex>);
  ~RegexTokenizer();

  Token get_token(std::string);
}


RegexTokenizer::RegexTokenizer(std::vector<token_regex> t_vec) {
  regexes_ = t_vec;
}


Token RegexTokenizer::get_token(std::string str) {
  std::vector<TokenType> candidates;
  std::vector<TokenType> old_candidates;
  std::string old_sub = "";
  for (size_t i = 1; i <= regexes_.size(); i++) {
    old_candidates = candidates;
    old_sub = sub;
    candidates.clear();
    std::string sub = str.substr(0, i);
    for (token_regex r : regexes_) {
      if (std::regex_match(sub, r.second)) {
        candidates.push_back(r.first);
      }
    }
    if (candidates.size() == 0) {
      Token t(old_candidates[0], old_sub);
      return t;
    }
  }
  Token t(TokenType::t_null, old_sub);
  return t;
}

#endif