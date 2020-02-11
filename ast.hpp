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
  TreeNode() : token_(Token()) {}
  TreeNode(Token t) : token_(t) {}
  void add_child(TreeNode);
  operator bool() const;
  bool is_terminal() const;
  bool is_epsilon() const;
  const Token& get_token() const;
  size_t size() const;
  TreeNode& operator[](size_t);
};

void TreeNode::add_child(TreeNode tn) {
  children_.push_back(tn);
}

TreeNode::operator bool() const {
  return token_.get_type() != TokenType::t_null;
}

bool TreeNode::is_terminal() const {
  return token_.is_terminal();
}

bool TreeNode::is_epsilon() const {
  return token_.get_type() == TokenType::epsilon;
}

const Token& TreeNode::get_token() const {
  return token_;
}

size_t TreeNode::size() const {
  return children_.size();
}

TreeNode& TreeNode::operator[](size_t i) {
  return children_[i];
}

#endif
