// A recursive descent parser

#ifndef RD_PARSER_HEADER
#define RD_PARSER_HEADER

#include <vector>
#include "cfg.hpp"
#include "token.hpp"


class RDParser {
private:
  Grammar cfg_;
  TokenType start_;
  std::vector<Token>::iterator next_;
  Grammar get_productions_(TokenType);
  bool terminal_(TokenType);
  bool production_(Production);
  bool all_productions_(TokenType);

public:
  RDParser(Grammar cfg, TokenType start_symbol) : cfg_(cfg), start_(start_symbol) {}
  TreeNode operator()(const std::vector<int>&);
};

Grammar RDParser::get_productions_(TokenType n) {
  Grammar g;
  for (Production p : cfg_) {
    if (p.left == n) {
      g.push_back(p);
    }
  }
  return g;
}

bool RDParser::terminal_(TokenType n) {
  return is_terminal(n) &&
         next_++->get_type() == n;
}

bool RDParser::production_(Production p) {
  for (TokenType t : p.right) {
    if (is_terminal(t)) {
      if (!terminal_(t)) return false;
    } else {
      if (!all_productions_(t)) return false;
    }
  }
  return true;
}

bool RDParser::all_productions_(TokenType n) {
  std::vector<TokenType>::iterator s = next_;
  for (Production p : get_productions_(n)) {
    bool res = production(p);
    if (res) return res;
    next_ = s;
  }
  return false;
}

TreeNode RDParser::operator()(const std::vector<Token>& tokens) {
  next_ = tokens.begin();

}


#endif
