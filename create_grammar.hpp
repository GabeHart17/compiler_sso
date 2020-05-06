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
v13.push_back(TokenType::t_return);
v13.push_back(TokenType::EXPR);
v13.push_back(TokenType::t_semicolon);
Production p13(TokenType::STATEMENT, v13);
g.push_back(p13);

std::vector<TokenType> v14;
v14.push_back(TokenType::t_break);
v14.push_back(TokenType::t_semicolon);
Production p14(TokenType::STATEMENT, v14);
g.push_back(p14);

std::vector<TokenType> v15;
v15.push_back(TokenType::CONDITION);
Production p15(TokenType::STATEMENT, v15);
g.push_back(p15);

std::vector<TokenType> v16;
v16.push_back(TokenType::LOOP);
Production p16(TokenType::STATEMENT, v16);
g.push_back(p16);

std::vector<TokenType> v17;
v17.push_back(TokenType::STATEMENT_BODY);
v17.push_back(TokenType::t_semicolon);
Production p17(TokenType::STATEMENT, v17);
g.push_back(p17);

std::vector<TokenType> v18;
v18.push_back(TokenType::EXPR);
Production p18(TokenType::STATEMENT_BODY, v18);
g.push_back(p18);

std::vector<TokenType> v19;
v19.push_back(TokenType::VAR_DECL);
Production p19(TokenType::STATEMENT_BODY, v19);
g.push_back(p19);

std::vector<TokenType> v20;
v20.push_back(TokenType::E12);
Production p20(TokenType::EXPR, v20);
g.push_back(p20);

std::vector<TokenType> v21;
v21.push_back(TokenType::t_paren_left);
v21.push_back(TokenType::EXPR);
v21.push_back(TokenType::t_paren_right);
Production p21(TokenType::E0, v21);
g.push_back(p21);

std::vector<TokenType> v22;
v22.push_back(TokenType::FUNCTION_CALL);
Production p22(TokenType::E0, v22);
g.push_back(p22);

std::vector<TokenType> v23;
v23.push_back(TokenType::R_VALUE);
Production p23(TokenType::E0, v23);
g.push_back(p23);

std::vector<TokenType> v24;
v24.push_back(TokenType::U1);
v24.push_back(TokenType::E1);
Production p24(TokenType::E1, v24);
g.push_back(p24);

std::vector<TokenType> v25;
v25.push_back(TokenType::E0);
v25.push_back(TokenType::S1);
Production p25(TokenType::E1, v25);
g.push_back(p25);

std::vector<TokenType> v26;
v26.push_back(TokenType::E1);
v26.push_back(TokenType::B2);
v26.push_back(TokenType::E2);
Production p26(TokenType::E2, v26);
g.push_back(p26);

std::vector<TokenType> v27;
v27.push_back(TokenType::E1);
Production p27(TokenType::E2, v27);
g.push_back(p27);

std::vector<TokenType> v28;
v28.push_back(TokenType::E2);
v28.push_back(TokenType::B3);
v28.push_back(TokenType::E3);
Production p28(TokenType::E3, v28);
g.push_back(p28);

std::vector<TokenType> v29;
v29.push_back(TokenType::E2);
Production p29(TokenType::E3, v29);
g.push_back(p29);

std::vector<TokenType> v30;
v30.push_back(TokenType::E3);
Production p30(TokenType::E4, v30);
g.push_back(p30);

std::vector<TokenType> v31;
v31.push_back(TokenType::E4);
v31.push_back(TokenType::B5);
v31.push_back(TokenType::E5);
Production p31(TokenType::E5, v31);
g.push_back(p31);

std::vector<TokenType> v32;
v32.push_back(TokenType::E4);
Production p32(TokenType::E5, v32);
g.push_back(p32);

std::vector<TokenType> v33;
v33.push_back(TokenType::E5);
v33.push_back(TokenType::B6);
v33.push_back(TokenType::E6);
Production p33(TokenType::E6, v33);
g.push_back(p33);

std::vector<TokenType> v34;
v34.push_back(TokenType::E5);
Production p34(TokenType::E6, v34);
g.push_back(p34);

std::vector<TokenType> v35;
v35.push_back(TokenType::E6);
v35.push_back(TokenType::t_bitwise_and);
v35.push_back(TokenType::E7);
Production p35(TokenType::E7, v35);
g.push_back(p35);

std::vector<TokenType> v36;
v36.push_back(TokenType::E6);
Production p36(TokenType::E7, v36);
g.push_back(p36);

std::vector<TokenType> v37;
v37.push_back(TokenType::E7);
Production p37(TokenType::E8, v37);
g.push_back(p37);

std::vector<TokenType> v38;
v38.push_back(TokenType::E8);
v38.push_back(TokenType::t_bitwise_or);
v38.push_back(TokenType::E9);
Production p38(TokenType::E9, v38);
g.push_back(p38);

std::vector<TokenType> v39;
v39.push_back(TokenType::E8);
Production p39(TokenType::E9, v39);
g.push_back(p39);

std::vector<TokenType> v40;
v40.push_back(TokenType::E9);
v40.push_back(TokenType::t_and);
v40.push_back(TokenType::E10);
Production p40(TokenType::E10, v40);
g.push_back(p40);

std::vector<TokenType> v41;
v41.push_back(TokenType::E9);
Production p41(TokenType::E10, v41);
g.push_back(p41);

std::vector<TokenType> v42;
v42.push_back(TokenType::E10);
v42.push_back(TokenType::t_or);
v42.push_back(TokenType::E11);
Production p42(TokenType::E11, v42);
g.push_back(p42);

std::vector<TokenType> v43;
v43.push_back(TokenType::E10);
Production p43(TokenType::E11, v43);
g.push_back(p43);

std::vector<TokenType> v44;
v44.push_back(TokenType::O12);
v44.push_back(TokenType::t_assign);
v44.push_back(TokenType::E12);
Production p44(TokenType::E12, v44);
g.push_back(p44);

std::vector<TokenType> v45;
v45.push_back(TokenType::E11);
Production p45(TokenType::E12, v45);
g.push_back(p45);

std::vector<TokenType> v46;
v46.push_back(TokenType::t_increment);
Production p46(TokenType::U1, v46);
g.push_back(p46);

std::vector<TokenType> v47;
v47.push_back(TokenType::t_decrement);
Production p47(TokenType::U1, v47);
g.push_back(p47);

std::vector<TokenType> v48;
v48.push_back(TokenType::t_not);
Production p48(TokenType::U1, v48);
g.push_back(p48);

std::vector<TokenType> v49;
v49.push_back(TokenType::t_bitwise_not);
Production p49(TokenType::U1, v49);
g.push_back(p49);

std::vector<TokenType> v50;
v50.push_back(TokenType::t_cast);
Production p50(TokenType::U1, v50);
g.push_back(p50);

std::vector<TokenType> v51;
v51.push_back(TokenType::t_dereference);
Production p51(TokenType::U1, v51);
g.push_back(p51);

std::vector<TokenType> v52;
v52.push_back(TokenType::t_reference);
Production p52(TokenType::U1, v52);
g.push_back(p52);

std::vector<TokenType> v53;
v53.push_back(TokenType::t_increment);
Production p53(TokenType::S1, v53);
g.push_back(p53);

std::vector<TokenType> v54;
v54.push_back(TokenType::t_decrement);
Production p54(TokenType::S1, v54);
g.push_back(p54);

std::vector<TokenType> v55;
v55.push_back(TokenType::epsilon);
Production p55(TokenType::S1, v55);
g.push_back(p55);

std::vector<TokenType> v56;
v56.push_back(TokenType::t_multiply);
Production p56(TokenType::B2, v56);
g.push_back(p56);

std::vector<TokenType> v57;
v57.push_back(TokenType::t_divide);
Production p57(TokenType::B2, v57);
g.push_back(p57);

std::vector<TokenType> v58;
v58.push_back(TokenType::t_modulo);
Production p58(TokenType::B2, v58);
g.push_back(p58);

std::vector<TokenType> v59;
v59.push_back(TokenType::t_plus);
Production p59(TokenType::B3, v59);
g.push_back(p59);

std::vector<TokenType> v60;
v60.push_back(TokenType::t_minus);
Production p60(TokenType::B3, v60);
g.push_back(p60);

std::vector<TokenType> v61;
v61.push_back(TokenType::t_less_than);
Production p61(TokenType::B5, v61);
g.push_back(p61);

std::vector<TokenType> v62;
v62.push_back(TokenType::t_greater_than);
Production p62(TokenType::B5, v62);
g.push_back(p62);

std::vector<TokenType> v63;
v63.push_back(TokenType::t_lt_or_eq);
Production p63(TokenType::B5, v63);
g.push_back(p63);

std::vector<TokenType> v64;
v64.push_back(TokenType::t_gt_or_eq);
Production p64(TokenType::B5, v64);
g.push_back(p64);

std::vector<TokenType> v65;
v65.push_back(TokenType::t_equal);
Production p65(TokenType::B6, v65);
g.push_back(p65);

std::vector<TokenType> v66;
v66.push_back(TokenType::t_not_equal);
Production p66(TokenType::B6, v66);
g.push_back(p66);

std::vector<TokenType> v67;
v67.push_back(TokenType::VAR_DECL);
Production p67(TokenType::O12, v67);
g.push_back(p67);

std::vector<TokenType> v68;
v68.push_back(TokenType::E11);
Production p68(TokenType::O12, v68);
g.push_back(p68);

std::vector<TokenType> v69;
v69.push_back(TokenType::t_if);
v69.push_back(TokenType::t_paren_left);
v69.push_back(TokenType::EXPR);
v69.push_back(TokenType::t_paren_right);
v69.push_back(TokenType::BLOCK);
v69.push_back(TokenType::ELSE_BLOCKS);
Production p69(TokenType::CONDITION, v69);
g.push_back(p69);

std::vector<TokenType> v70;
v70.push_back(TokenType::t_else);
v70.push_back(TokenType::BLOCK);
Production p70(TokenType::ELSE_BLOCKS, v70);
g.push_back(p70);

std::vector<TokenType> v71;
v71.push_back(TokenType::t_else);
v71.push_back(TokenType::CONDITION);
Production p71(TokenType::ELSE_BLOCKS, v71);
g.push_back(p71);

std::vector<TokenType> v72;
v72.push_back(TokenType::epsilon);
Production p72(TokenType::ELSE_BLOCKS, v72);
g.push_back(p72);

std::vector<TokenType> v73;
v73.push_back(TokenType::t_ident);
v73.push_back(TokenType::t_paren_left);
v73.push_back(TokenType::CALL_ARGS);
v73.push_back(TokenType::t_paren_right);
Production p73(TokenType::FUNCTION_CALL, v73);
g.push_back(p73);

std::vector<TokenType> v74;
v74.push_back(TokenType::EXPR);
v74.push_back(TokenType::CALL_ARGS_S);
Production p74(TokenType::CALL_ARGS, v74);
g.push_back(p74);

std::vector<TokenType> v75;
v75.push_back(TokenType::epsilon);
Production p75(TokenType::CALL_ARGS, v75);
g.push_back(p75);

std::vector<TokenType> v76;
v76.push_back(TokenType::t_coma);
v76.push_back(TokenType::CALL_ARGS);
Production p76(TokenType::CALL_ARGS_S, v76);
g.push_back(p76);

std::vector<TokenType> v77;
v77.push_back(TokenType::epsilon);
Production p77(TokenType::CALL_ARGS_S, v77);
g.push_back(p77);

std::vector<TokenType> v78;
v78.push_back(TokenType::FOR_LOOP);
Production p78(TokenType::LOOP, v78);
g.push_back(p78);

std::vector<TokenType> v79;
v79.push_back(TokenType::WHILE_LOOP);
Production p79(TokenType::LOOP, v79);
g.push_back(p79);

std::vector<TokenType> v80;
v80.push_back(TokenType::t_for);
v80.push_back(TokenType::t_paren_left);
v80.push_back(TokenType::FOR_STATEMENT);
v80.push_back(TokenType::t_semicolon);
v80.push_back(TokenType::FOR_CONDITION);
v80.push_back(TokenType::t_semicolon);
v80.push_back(TokenType::FOR_STATEMENT);
v80.push_back(TokenType::t_paren_right);
v80.push_back(TokenType::BLOCK);
Production p80(TokenType::FOR_LOOP, v80);
g.push_back(p80);

std::vector<TokenType> v81;
v81.push_back(TokenType::STATEMENT_BODY);
Production p81(TokenType::FOR_STATEMENT, v81);
g.push_back(p81);

std::vector<TokenType> v82;
v82.push_back(TokenType::epsilon);
Production p82(TokenType::FOR_STATEMENT, v82);
g.push_back(p82);

std::vector<TokenType> v83;
v83.push_back(TokenType::EXPR);
Production p83(TokenType::FOR_CONDITION, v83);
g.push_back(p83);

std::vector<TokenType> v84;
v84.push_back(TokenType::epsilon);
Production p84(TokenType::FOR_CONDITION, v84);
g.push_back(p84);

std::vector<TokenType> v85;
v85.push_back(TokenType::t_while);
v85.push_back(TokenType::t_paren_left);
v85.push_back(TokenType::EXPR);
v85.push_back(TokenType::t_paren_right);
v85.push_back(TokenType::BLOCK);
Production p85(TokenType::WHILE_LOOP, v85);
g.push_back(p85);

std::vector<TokenType> v86;
v86.push_back(TokenType::t_bool);
Production p86(TokenType::TYPE_NAME, v86);
g.push_back(p86);

std::vector<TokenType> v87;
v87.push_back(TokenType::t_char);
Production p87(TokenType::TYPE_NAME, v87);
g.push_back(p87);

std::vector<TokenType> v88;
v88.push_back(TokenType::t_float);
Production p88(TokenType::TYPE_NAME, v88);
g.push_back(p88);

std::vector<TokenType> v89;
v89.push_back(TokenType::t_int);
Production p89(TokenType::TYPE_NAME, v89);
g.push_back(p89);

std::vector<TokenType> v90;
v90.push_back(TokenType::t_pointer);
Production p90(TokenType::TYPE_NAME, v90);
g.push_back(p90);

std::vector<TokenType> v91;
v91.push_back(TokenType::t_literal_int);
Production p91(TokenType::R_VALUE, v91);
g.push_back(p91);

std::vector<TokenType> v92;
v92.push_back(TokenType::t_literal_float);
Production p92(TokenType::R_VALUE, v92);
g.push_back(p92);

std::vector<TokenType> v93;
v93.push_back(TokenType::t_literal_char);
Production p93(TokenType::R_VALUE, v93);
g.push_back(p93);

std::vector<TokenType> v94;
v94.push_back(TokenType::t_literal_string);
Production p94(TokenType::R_VALUE, v94);
g.push_back(p94);

std::vector<TokenType> v95;
v95.push_back(TokenType::t_literal_bool);
Production p95(TokenType::R_VALUE, v95);
g.push_back(p95);

std::vector<TokenType> v96;
v96.push_back(TokenType::t_ident);
Production p96(TokenType::R_VALUE, v96);
g.push_back(p96);


return g;
}
#endif
