#ifndef AST_HEADER
#define AST_HEADER

#include <vector>
#include "token.hpp"
#include "cfg.hpp"


class TreeNode {
private:
  std::vector<TreeNode> children_;
public:
  void add_child(TreeNode);
  virtual bool is_terminal();
};


#endif
