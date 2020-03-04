#ifndef CREATE_GRAMMAR_HEADER
#define CREATE_GRAMMAR_HEADER
#include "token.hpp"
#include "cfg.hpp"
#include <vector>

Grammar create_grammar() {
Grammar g;

std::vector<TokenType> v0;
v0.push_back(TokenType::FUNCTION);
v0.push_back(TokenType::PROGRAM);
Production p0(TokenType::PROGRAM, v0);
g.push_back(p0);

std::vector<TokenType> v1;
v1.push_back(TokenType::VAR_DECL);
v1.push_back(TokenType::PROGRAM);
Production p1(TokenType::PROGRAM, v1);
g.push_back(p1);

std::vector<TokenType> v2;
v2.push_back(TokenType::epsilon);
Production p2(TokenType::PROGRAM, v2);
g.push_back(p2);

std::vector<TokenType> v3;
v3.push_back(TokenType::VAR_DECL);
v3.push_back(TokenType::t_paren_left);
v3.push_back(TokenType::F_DECL_ARGS);
v3.push_back(TokenType::t_paren_right);
v3.push_back(TokenType::BLOCK);
Production p3(TokenType::FUNCTION, v3);
g.push_back(p3);

std::vector<TokenType> v4;
v4.push_back(TokenType::TYPE_NAME);
v4.push_back(TokenType::t_ident);
Production p4(TokenType::VAR_DECL, v4);
g.push_back(p4);

std::vector<TokenType> v5;
v5.push_back(TokenType::ARG_DECLS);
Production p5(TokenType::F_DECL_ARGS, v5);
g.push_back(p5);

std::vector<TokenType> v6;
v6.push_back(TokenType::epsilon);
Production p6(TokenType::F_DECL_ARGS, v6);
g.push_back(p6);

std::vector<TokenType> v7;
v7.push_back(TokenType::VAR_DECL);
v7.push_back(TokenType::t_coma);
v7.push_back(TokenType::ARG_DECLS);
Production p7(TokenType::ARG_DECLS, v7);
g.push_back(p7);

std::vector<TokenType> v8;
v8.push_back(TokenType::VAR_DECL);
Production p8(TokenType::ARG_DECLS, v8);
g.push_back(p8);

std::vector<TokenType> v9;
v9.push_back(TokenType::t_curly_left);
v9.push_back(TokenType::STATEMENTS);
v9.push_back(TokenType::t_curly_right);
Production p9(TokenType::BLOCK, v9);
g.push_back(p9);

std::vector<TokenType> v10;
v10.push_back(TokenType::STATEMENT);
v10.push_back(TokenType::t_semicolon);
Production p10(TokenType::BLOCK, v10);
g.push_back(p10);

std::vector<TokenType> v11;
v11.push_back(TokenType::STATEMENT);
v11.push_back(TokenType::STATEMENTS);
Production p11(TokenType::STATEMENTS, v11);
g.push_back(p11);

std::vector<TokenType> v12;
v12.push_back(TokenType::epsilon);
Production p12(TokenType::STATEMENTS, v12);
g.push_back(p12);

std::vector<TokenType> v13;
v13.push_back(TokenType::EXPR);
v13.push_back(TokenType::t_semicolon);
Production p13(TokenType::STATEMENT, v13);
g.push_back(p13);

std::vector<TokenType> v14;
v14.push_back(TokenType::E12);
Production p14(TokenType::EXPR, v14);
g.push_back(p14);

std::vector<TokenType> v15;
v15.push_back(TokenType::t_paren_left);
v15.push_back(TokenType::EXPR);
v15.push_back(TokenType::t_paren_right);
Production p15(TokenType::E0, v15);
g.push_back(p15);

std::vector<TokenType> v16;
v16.push_back(TokenType::R_VALUE);
Production p16(TokenType::E0, v16);
g.push_back(p16);

std::vector<TokenType> v17;
v17.push_back(TokenType::t_increment);
v17.push_back(TokenType::E1);
Production p17(TokenType::E1, v17);
g.push_back(p17);

std::vector<TokenType> v18;
v18.push_back(TokenType::t_decrement);
v18.push_back(TokenType::E1);
Production p18(TokenType::E1, v18);
g.push_back(p18);

std::vector<TokenType> v19;
v19.push_back(TokenType::t_not);
v19.push_back(TokenType::E1);
Production p19(TokenType::E1, v19);
g.push_back(p19);

std::vector<TokenType> v20;
v20.push_back(TokenType::t_bitwise_not);
v20.push_back(TokenType::E1);
Production p20(TokenType::E1, v20);
g.push_back(p20);

std::vector<TokenType> v21;
v21.push_back(TokenType::t_cast);
v21.push_back(TokenType::E1);
Production p21(TokenType::E1, v21);
g.push_back(p21);

std::vector<TokenType> v22;
v22.push_back(TokenType::t_dereference);
v22.push_back(TokenType::E1);
Production p22(TokenType::E1, v22);
g.push_back(p22);

std::vector<TokenType> v23;
v23.push_back(TokenType::t_reference);
v23.push_back(TokenType::E1);
Production p23(TokenType::E1, v23);
g.push_back(p23);

std::vector<TokenType> v24;
v24.push_back(TokenType::E0);
Production p24(TokenType::E1, v24);
g.push_back(p24);

std::vector<TokenType> v25;
v25.push_back(TokenType::E1);
v25.push_back(TokenType::t_multiply);
v25.push_back(TokenType::E2);
Production p25(TokenType::E2, v25);
g.push_back(p25);

std::vector<TokenType> v26;
v26.push_back(TokenType::E1);
v26.push_back(TokenType::t_divide);
v26.push_back(TokenType::E2);
Production p26(TokenType::E2, v26);
g.push_back(p26);

std::vector<TokenType> v27;
v27.push_back(TokenType::E1);
v27.push_back(TokenType::t_modulo);
v27.push_back(TokenType::E2);
Production p27(TokenType::E2, v27);
g.push_back(p27);

std::vector<TokenType> v28;
v28.push_back(TokenType::E1);
Production p28(TokenType::E2, v28);
g.push_back(p28);

std::vector<TokenType> v29;
v29.push_back(TokenType::E2);
v29.push_back(TokenType::t_plus);
v29.push_back(TokenType::E3);
Production p29(TokenType::E3, v29);
g.push_back(p29);

std::vector<TokenType> v30;
v30.push_back(TokenType::E2);
v30.push_back(TokenType::t_minus);
v30.push_back(TokenType::E3);
Production p30(TokenType::E3, v30);
g.push_back(p30);

std::vector<TokenType> v31;
v31.push_back(TokenType::E2);
Production p31(TokenType::E3, v31);
g.push_back(p31);

std::vector<TokenType> v32;
v32.push_back(TokenType::E3);
Production p32(TokenType::E4, v32);
g.push_back(p32);

std::vector<TokenType> v33;
v33.push_back(TokenType::E4);
v33.push_back(TokenType::t_less_than);
v33.push_back(TokenType::E5);
Production p33(TokenType::E5, v33);
g.push_back(p33);

std::vector<TokenType> v34;
v34.push_back(TokenType::E4);
v34.push_back(TokenType::t_greater_than);
v34.push_back(TokenType::E5);
Production p34(TokenType::E5, v34);
g.push_back(p34);

std::vector<TokenType> v35;
v35.push_back(TokenType::E4);
v35.push_back(TokenType::t_lt_or_eq);
v35.push_back(TokenType::E5);
Production p35(TokenType::E5, v35);
g.push_back(p35);

std::vector<TokenType> v36;
v36.push_back(TokenType::E4);
v36.push_back(TokenType::t_gt_or_eq);
v36.push_back(TokenType::E5);
Production p36(TokenType::E5, v36);
g.push_back(p36);

std::vector<TokenType> v37;
v37.push_back(TokenType::E4);
Production p37(TokenType::E5, v37);
g.push_back(p37);

std::vector<TokenType> v38;
v38.push_back(TokenType::E5);
v38.push_back(TokenType::t_equal);
v38.push_back(TokenType::E6);
Production p38(TokenType::E6, v38);
g.push_back(p38);

std::vector<TokenType> v39;
v39.push_back(TokenType::E5);
v39.push_back(TokenType::t_not_equal);
v39.push_back(TokenType::E6);
Production p39(TokenType::E6, v39);
g.push_back(p39);

std::vector<TokenType> v40;
v40.push_back(TokenType::E5);
Production p40(TokenType::E6, v40);
g.push_back(p40);

std::vector<TokenType> v41;
v41.push_back(TokenType::E6);
v41.push_back(TokenType::t_bitwise_and);
v41.push_back(TokenType::E7);
Production p41(TokenType::E7, v41);
g.push_back(p41);

std::vector<TokenType> v42;
v42.push_back(TokenType::E6);
Production p42(TokenType::E7, v42);
g.push_back(p42);

std::vector<TokenType> v43;
v43.push_back(TokenType::E7);
Production p43(TokenType::E8, v43);
g.push_back(p43);

std::vector<TokenType> v44;
v44.push_back(TokenType::E8);
v44.push_back(TokenType::t_bitwise_or);
v44.push_back(TokenType::E9);
Production p44(TokenType::E9, v44);
g.push_back(p44);

std::vector<TokenType> v45;
v45.push_back(TokenType::E8);
Production p45(TokenType::E9, v45);
g.push_back(p45);

std::vector<TokenType> v46;
v46.push_back(TokenType::E9);
v46.push_back(TokenType::t_and);
v46.push_back(TokenType::E10);
Production p46(TokenType::E10, v46);
g.push_back(p46);

std::vector<TokenType> v47;
v47.push_back(TokenType::E9);
Production p47(TokenType::E10, v47);
g.push_back(p47);

std::vector<TokenType> v48;
v48.push_back(TokenType::E10);
v48.push_back(TokenType::t_or);
v48.push_back(TokenType::E11);
Production p48(TokenType::E11, v48);
g.push_back(p48);

std::vector<TokenType> v49;
v49.push_back(TokenType::E10);
Production p49(TokenType::E11, v49);
g.push_back(p49);

std::vector<TokenType> v50;
v50.push_back(TokenType::E11);
v50.push_back(TokenType::t_assign);
v50.push_back(TokenType::E12);
Production p50(TokenType::E12, v50);
g.push_back(p50);

std::vector<TokenType> v51;
v51.push_back(TokenType::E11);
Production p51(TokenType::E12, v51);
g.push_back(p51);

std::vector<TokenType> v52;
v52.push_back(TokenType::t_bool);
Production p52(TokenType::TYPE_NAME, v52);
g.push_back(p52);

std::vector<TokenType> v53;
v53.push_back(TokenType::t_char);
Production p53(TokenType::TYPE_NAME, v53);
g.push_back(p53);

std::vector<TokenType> v54;
v54.push_back(TokenType::t_float);
Production p54(TokenType::TYPE_NAME, v54);
g.push_back(p54);

std::vector<TokenType> v55;
v55.push_back(TokenType::t_int);
Production p55(TokenType::TYPE_NAME, v55);
g.push_back(p55);

std::vector<TokenType> v56;
v56.push_back(TokenType::t_pointer);
Production p56(TokenType::TYPE_NAME, v56);
g.push_back(p56);

std::vector<TokenType> v57;
v57.push_back(TokenType::t_literal_int);
Production p57(TokenType::R_VALUE, v57);
g.push_back(p57);

std::vector<TokenType> v58;
v58.push_back(TokenType::t_literal_float);
Production p58(TokenType::R_VALUE, v58);
g.push_back(p58);

std::vector<TokenType> v59;
v59.push_back(TokenType::t_ident);
Production p59(TokenType::R_VALUE, v59);
g.push_back(p59);


return g;
}
#endif
