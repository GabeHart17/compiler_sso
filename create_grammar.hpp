// rename this file to `create_grammar.hpp` in order to use

#ifndef CREATE_GRAMMAR_HEADER
#define CREATE_GRAMMAR_HEADER

#include "token.hpp"
#include "cfg.hpp"
#include <vector>

Grammar create_grammar() {
Grammar g;

std::vector<TokenType> v0;
v0.push_back(TokenType::EXPR);
Production p0(TokenType::PROGRAM, v0);
g.push_back(p0);

std::vector<TokenType> v1;
v1.push_back(TokenType::E2);
Production p1(TokenType::EXPR, v1);
g.push_back(p1);

std::vector<TokenType> v2;
v2.push_back(TokenType::t_paren_left);
v2.push_back(TokenType::EXPR);
v2.push_back(TokenType::t_paren_right);
Production p2(TokenType::E0, v2);
g.push_back(p2);

std::vector<TokenType> v3;
v3.push_back(TokenType::t_literal_int);
Production p3(TokenType::E0, v3);
g.push_back(p3);

std::vector<TokenType> v4;
v4.push_back(TokenType::E0);
v4.push_back(TokenType::t_multiply);
v4.push_back(TokenType::E1);
Production p4(TokenType::E1, v4);
g.push_back(p4);

std::vector<TokenType> v5;
v5.push_back(TokenType::E0);
Production p5(TokenType::E1, v5);
g.push_back(p5);

std::vector<TokenType> v6;
v6.push_back(TokenType::E1);
v6.push_back(TokenType::t_plus);
v6.push_back(TokenType::E2);
Production p6(TokenType::E2, v6);
g.push_back(p6);

std::vector<TokenType> v7;
v7.push_back(TokenType::E1);
Production p7(TokenType::E2, v7);
g.push_back(p7);


return g;
}

#endif
