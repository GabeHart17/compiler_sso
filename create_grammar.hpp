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
v2.push_back(TokenType::t_eof);
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
v17.push_back(TokenType::U1);
v17.push_back(TokenType::E1);
Production p17(TokenType::E1, v17);
g.push_back(p17);

std::vector<TokenType> v18;
v18.push_back(TokenType::E0);
Production p18(TokenType::E1, v18);
g.push_back(p18);

std::vector<TokenType> v19;
v19.push_back(TokenType::E1);
v19.push_back(TokenType::B2);
v19.push_back(TokenType::E2);
Production p19(TokenType::E2, v19);
g.push_back(p19);

std::vector<TokenType> v20;
v20.push_back(TokenType::E1);
Production p20(TokenType::E2, v20);
g.push_back(p20);

std::vector<TokenType> v21;
v21.push_back(TokenType::E2);
v21.push_back(TokenType::B3);
v21.push_back(TokenType::E3);
Production p21(TokenType::E3, v21);
g.push_back(p21);

std::vector<TokenType> v22;
v22.push_back(TokenType::E2);
Production p22(TokenType::E3, v22);
g.push_back(p22);

std::vector<TokenType> v23;
v23.push_back(TokenType::E3);
Production p23(TokenType::E4, v23);
g.push_back(p23);

std::vector<TokenType> v24;
v24.push_back(TokenType::E4);
v24.push_back(TokenType::B5);
v24.push_back(TokenType::E5);
Production p24(TokenType::E5, v24);
g.push_back(p24);

std::vector<TokenType> v25;
v25.push_back(TokenType::E4);
Production p25(TokenType::E5, v25);
g.push_back(p25);

std::vector<TokenType> v26;
v26.push_back(TokenType::E5);
v26.push_back(TokenType::B6);
v26.push_back(TokenType::E6);
Production p26(TokenType::E6, v26);
g.push_back(p26);

std::vector<TokenType> v27;
v27.push_back(TokenType::E5);
Production p27(TokenType::E6, v27);
g.push_back(p27);

std::vector<TokenType> v28;
v28.push_back(TokenType::E6);
v28.push_back(TokenType::t_bitwise_and);
v28.push_back(TokenType::E7);
Production p28(TokenType::E7, v28);
g.push_back(p28);

std::vector<TokenType> v29;
v29.push_back(TokenType::E6);
Production p29(TokenType::E7, v29);
g.push_back(p29);

std::vector<TokenType> v30;
v30.push_back(TokenType::E7);
Production p30(TokenType::E8, v30);
g.push_back(p30);

std::vector<TokenType> v31;
v31.push_back(TokenType::E8);
v31.push_back(TokenType::t_bitwise_or);
v31.push_back(TokenType::E9);
Production p31(TokenType::E9, v31);
g.push_back(p31);

std::vector<TokenType> v32;
v32.push_back(TokenType::E8);
Production p32(TokenType::E9, v32);
g.push_back(p32);

std::vector<TokenType> v33;
v33.push_back(TokenType::E9);
v33.push_back(TokenType::t_and);
v33.push_back(TokenType::E10);
Production p33(TokenType::E10, v33);
g.push_back(p33);

std::vector<TokenType> v34;
v34.push_back(TokenType::E9);
Production p34(TokenType::E10, v34);
g.push_back(p34);

std::vector<TokenType> v35;
v35.push_back(TokenType::E10);
v35.push_back(TokenType::t_or);
v35.push_back(TokenType::E11);
Production p35(TokenType::E11, v35);
g.push_back(p35);

std::vector<TokenType> v36;
v36.push_back(TokenType::E10);
Production p36(TokenType::E11, v36);
g.push_back(p36);

std::vector<TokenType> v37;
v37.push_back(TokenType::E11);
v37.push_back(TokenType::t_assign);
v37.push_back(TokenType::E12);
Production p37(TokenType::E12, v37);
g.push_back(p37);

std::vector<TokenType> v38;
v38.push_back(TokenType::E11);
Production p38(TokenType::E12, v38);
g.push_back(p38);

std::vector<TokenType> v39;
v39.push_back(TokenType::t_increment);
Production p39(TokenType::U1, v39);
g.push_back(p39);

std::vector<TokenType> v40;
v40.push_back(TokenType::t_decrement);
Production p40(TokenType::U1, v40);
g.push_back(p40);

std::vector<TokenType> v41;
v41.push_back(TokenType::t_not);
Production p41(TokenType::U1, v41);
g.push_back(p41);

std::vector<TokenType> v42;
v42.push_back(TokenType::t_bitwise_not);
Production p42(TokenType::U1, v42);
g.push_back(p42);

std::vector<TokenType> v43;
v43.push_back(TokenType::t_cast);
Production p43(TokenType::U1, v43);
g.push_back(p43);

std::vector<TokenType> v44;
v44.push_back(TokenType::t_dereference);
Production p44(TokenType::U1, v44);
g.push_back(p44);

std::vector<TokenType> v45;
v45.push_back(TokenType::t_reference);
Production p45(TokenType::U1, v45);
g.push_back(p45);

std::vector<TokenType> v46;
v46.push_back(TokenType::t_multiply);
Production p46(TokenType::B2, v46);
g.push_back(p46);

std::vector<TokenType> v47;
v47.push_back(TokenType::t_divide);
Production p47(TokenType::B2, v47);
g.push_back(p47);

std::vector<TokenType> v48;
v48.push_back(TokenType::t_modulo);
Production p48(TokenType::B2, v48);
g.push_back(p48);

std::vector<TokenType> v49;
v49.push_back(TokenType::t_plus);
Production p49(TokenType::B3, v49);
g.push_back(p49);

std::vector<TokenType> v50;
v50.push_back(TokenType::t_minus);
Production p50(TokenType::B3, v50);
g.push_back(p50);

std::vector<TokenType> v51;
v51.push_back(TokenType::t_less_than);
Production p51(TokenType::B5, v51);
g.push_back(p51);

std::vector<TokenType> v52;
v52.push_back(TokenType::t_greater_than);
Production p52(TokenType::B5, v52);
g.push_back(p52);

std::vector<TokenType> v53;
v53.push_back(TokenType::t_lt_or_eq);
Production p53(TokenType::B5, v53);
g.push_back(p53);

std::vector<TokenType> v54;
v54.push_back(TokenType::t_gt_or_eq);
Production p54(TokenType::B5, v54);
g.push_back(p54);

std::vector<TokenType> v55;
v55.push_back(TokenType::t_equal);
Production p55(TokenType::B6, v55);
g.push_back(p55);

std::vector<TokenType> v56;
v56.push_back(TokenType::t_not_equal);
Production p56(TokenType::B6, v56);
g.push_back(p56);

std::vector<TokenType> v57;
v57.push_back(TokenType::t_bool);
Production p57(TokenType::TYPE_NAME, v57);
g.push_back(p57);

std::vector<TokenType> v58;
v58.push_back(TokenType::t_char);
Production p58(TokenType::TYPE_NAME, v58);
g.push_back(p58);

std::vector<TokenType> v59;
v59.push_back(TokenType::t_float);
Production p59(TokenType::TYPE_NAME, v59);
g.push_back(p59);

std::vector<TokenType> v60;
v60.push_back(TokenType::t_int);
Production p60(TokenType::TYPE_NAME, v60);
g.push_back(p60);

std::vector<TokenType> v61;
v61.push_back(TokenType::t_pointer);
Production p61(TokenType::TYPE_NAME, v61);
g.push_back(p61);

std::vector<TokenType> v62;
v62.push_back(TokenType::t_literal_int);
Production p62(TokenType::R_VALUE, v62);
g.push_back(p62);

std::vector<TokenType> v63;
v63.push_back(TokenType::t_literal_float);
Production p63(TokenType::R_VALUE, v63);
g.push_back(p63);

std::vector<TokenType> v64;
v64.push_back(TokenType::t_ident);
Production p64(TokenType::R_VALUE, v64);
g.push_back(p64);


return g;
}
#endif
