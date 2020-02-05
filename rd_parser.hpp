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
  TreeNode production_(Production);
  TreeNode all_productions_(TokenType);

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

TreeNode RDParser::production_(Production p) {
  TreeNode tn(Token(p.left));
  if (p.right[0] == TokenType::epsilon) {
    return TreeNode(Token(TokenType::epsilon));
  }
  for (TokenType t : p.right) {
    if (is_terminal(t)) {
      if (terminal_(t)){
        tn.add_child(TreeNode(*(next_-1)));
      } else {
        return TreeNode();
      }
    } else {
      TreeNode ap = all_productions_(t);
      if (ap){
        if (!ap.is_epsilon()) tn.add_child(TreeNode(Token(t)));
      } else {
        return TreeNode();
      }
    }
  }
  return tn;;
}

TreeNode RDParser::all_productions_(TokenType n) {
  std::vector<TokenType>::iterator s = next_;
  for (Production p : get_productions_(n)) {
    TreeNode res = production_(p);
    if (res) return res;
    next_ = s;
  }
  return TreeNode();
}

TreeNode RDParser::operator()(const std::vector<Token>& tokens) {
  next_ = tokens.begin();
  return all_productions_(start_);
}


#endif
