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
   std::string strip_(std::string);

public:
  RegexTokenizer(std::vector<token_regex>);
  ~RegexTokenizer() {}

  Token get_token(const std::string&);
};


RegexTokenizer::RegexTokenizer(std::vector<token_regex> t_vec) {
  regexes_ = t_vec;
}


std::string RegexTokenizer::strip_(std::string s) {
  std::string whitespace = " \f\n\r\t\v";
  size_t f = s.find_first_not_of(whitespace);
  size_t l = s.find_last_not_of(whitespace);
  unsigned int len = l - f;
  return s.substr(f, len);
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
      Token t(old_candidates[0], old_sub);
      return t;
    }
  }
  Token t(TokenType::t_null, old_sub);
  return t;
}

#endif
