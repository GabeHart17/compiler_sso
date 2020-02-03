#ifndef AST_HEADER
#define AST_HEADER

#include <vector>
#include "token.hpp"
#include "cfg.hpp"


class TreeNode {
private:
  std::vector<TreeNode> children_;
  const Token token_;
public:
  TreeNode(Token t) : token_(t) {}
  void add_child(TreeNode);
  operator bool() const;
  bool is_terminal() const;
};

void TreeNode::add_child(TreeNode tn) {
  children_.push_back(tn);
}

TreeNode::operator bool() const {
  return !children_.empty();
}

bool TreeNode::is_terminal() {
  return token_.is_terminal();
}

#endif
