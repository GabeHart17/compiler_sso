#ifndef CREATE_GRAMMAR_HEADER
#define CREATE_GRAMMAR_HEADER
#include "token.hpp"
#include "cfg.hpp"
#include <vector>

Grammar create_grammar() {
Grammar g;

std::vector<TokenType> v0;
v0.push_back(TokenType::STATEMENTS);
Production p0(TokenType::PROGRAM, v0);
g.push_back(p0);

std::vector<TokenType> v1;
v1.push_back(TokenType::epsilon);
Production p1(TokenType::PROGRAM, v1);
g.push_back(p1);

std::vector<TokenType> v2;
v2.push_back(TokenType::STATEMENT);
v2.push_back(TokenType::STATEMENTS);
Production p2(TokenType::STATEMENTS, v2);
g.push_back(p2);

std::vector<TokenType> v3;
v3.push_back(TokenType::epsilon);
Production p3(TokenType::STATEMENTS, v3);
g.push_back(p3);

std::vector<TokenType> v4;
v4.push_back(TokenType::EXPR);
v4.push_back(TokenType::t_semicolon);
Production p4(TokenType::STATEMENT, v4);
g.push_back(p4);

std::vector<TokenType> v5;
v5.push_back(TokenType::E2);
Production p5(TokenType::EXPR, v5);
g.push_back(p5);

std::vector<TokenType> v6;
v6.push_back(TokenType::t_paren_left);
v6.push_back(TokenType::EXPR);
v6.push_back(TokenType::t_paren_right);
Production p6(TokenType::E0, v6);
g.push_back(p6);

std::vector<TokenType> v7;
v7.push_back(TokenType::R_VALUE);
Production p7(TokenType::E0, v7);
g.push_back(p7);

std::vector<TokenType> v8;
v8.push_back(TokenType::E0);
v8.push_back(TokenType::t_multiply);
v8.push_back(TokenType::E1);
Production p8(TokenType::E1, v8);
g.push_back(p8);

std::vector<TokenType> v9;
v9.push_back(TokenType::E0);
Production p9(TokenType::E1, v9);
g.push_back(p9);

std::vector<TokenType> v10;
v10.push_back(TokenType::E1);
v10.push_back(TokenType::t_plus);
v10.push_back(TokenType::E2);
Production p10(TokenType::E2, v10);
g.push_back(p10);

std::vector<TokenType> v11;
v11.push_back(TokenType::E1);
Production p11(TokenType::E2, v11);
g.push_back(p11);

std::vector<TokenType> v12;
v12.push_back(TokenType::t_literal_int);
Production p12(TokenType::R_VALUE, v12);
g.push_back(p12);

std::vector<TokenType> v13;
v13.push_back(TokenType::t_literal_float);
Production p13(TokenType::R_VALUE, v13);
g.push_back(p13);

std::vector<TokenType> v14;
v14.push_back(TokenType::t_ident);
Production p14(TokenType::R_VALUE, v14);
g.push_back(p14);


return g;
}
#endif
