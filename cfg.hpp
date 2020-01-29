#ifndef CFG_HEADER
#define CFG_HEADER

#include <vector>
#include "token.hpp"

class Production {
public:
  const TokenType left;
  const std::vector<TokenType> right;
  Production(TokenType l, std::vector<TokenType> r) : left(l), right(r) {}
};


#endif
