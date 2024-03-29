#ifndef REGEX_TOKENIZER_HEADER
#define REGEX_TOKENIZER_HEADER

#include "token.hpp"
#include <vector>
#include <utility>
#include <regex>
#include <string>


typedef std::pair<TokenType, std::regex> token_regex;


class RegexTokenizer {
private:
   std::vector<token_regex> regexes_;

public:
  RegexTokenizer(std::vector<token_regex>);
  ~RegexTokenizer() {}

  Token get_token(const std::string&);
};


RegexTokenizer::RegexTokenizer(std::vector<token_regex> t_vec) {
  regexes_ = t_vec;
}


Token RegexTokenizer::get_token(const std::string& str) {
  std::vector<TokenType> candidates;
  std::vector<TokenType> old_candidates;
  std::string sub = "";
  std::string old_sub = "";
  for (size_t i = 1; i <= str.size(); i++) {
    old_candidates = candidates;
    old_sub = sub;
    sub = str.substr(0, i);
    candidates.clear();
    for (token_regex r : regexes_) {
      if (std::regex_match(sub, r.second)) {
        candidates.push_back(r.first);
      }
    }
    if (candidates.size() == 0) {
      if (old_candidates.size() != 0) {
        Token t(old_candidates[0], old_sub);
        return t;
      }
    }
  }
  if (candidates.size() != 0) {
    Token t(candidates[0], sub);
    return t;
  }
  Token t(TokenType::t_null, sub);
  return t;
}

#endif
