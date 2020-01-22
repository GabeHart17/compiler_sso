#ifndef CFG_HEADER
#define CFG_HEADER

#include <vector>
#include "token.hpp"

enum class Nonterminal {
  PROGRAM = 1000,
  BLOCK,
  EXPR,
  STMT,
  STMTS,
  CONDITION,
  ELSE_BLOCKS,
  // TODO
  // finish this
}

struct Production {
  const int left;
  const std::vector<int> right;
  Production(int l, std::vector<int> r) : left(l), right(r) {}
};

class CFG {
private:
  std::vector<Production> productions_;

public:
  CFG(std::vector<Production>);
  std::vector<int> first(int);
  std::vector<int> follow(int);
}

#endif
