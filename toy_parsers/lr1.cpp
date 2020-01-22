#include <string>
#include <iostream>
#include <vector>
#include "../token.hpp"
#include "../tokenizer.hpp"





struct TreeNode {
  Token token;
  std::vector<TreeNode> children;
  TreeNode(Token t) : token(t) {}
};


int main(int argc, char const *argv[]) {
  Tokenizer tokenizer;
  std::vector<Token> raw_tokens  = tokenizer.tokenize("78 + (98 * 3)");
  std::vector<Token> tokens;
  for (Token t : raw_tokens) {
    if (
      t.get_type() == TokenType::t_literal_int ||
      t.get_type() == TokenType::t_plus ||
      t.get_type() == TokenType::t_multiply ||
      t.get_type() == TokenType::t_paren_left ||
      t.get_type() == TokenType::t_paren_right
    ) {
      tokens.push_back(t);
    }
  }
  for (Token t: tokens) {
    std::cout << (int) t.get_type() << '\t' << t.get_lexeme() << '\n';
  }
  return 0;
}
