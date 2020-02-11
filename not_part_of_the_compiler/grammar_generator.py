"""
generates a header file with a create_gammar() function that returns a Grammar object

input is a file with lines of the form NONTERMINAL ::= production | production | production
where a production is a sequence of terminals and nonterminals

in the header, all terminals and nonterminals are assumed to belong to a namespace called TokenType
"""

import sys


vector_id = 0
production_id = 0

def create_production(lhs, rhs):
    global vector_id, production_id
    res0 = f"std::vector<TokenType> v{vector_id};"
    for r in rhs:
        res0 += f"\nv{vector_id}.push_back(TokenType::{r});";
    res1 = f"\nProduction p{production_id}(TokenType::{lhs}, v{vector_id});\n"
    res = res0 + res1 + f"g.push_back(p{production_id});\n"
    vector_id += 1
    production_id += 1
    return res

with open(sys.argv[1]) as in_file:
    raw = [i for i in in_file.readlines() if i.strip()]

out_lines = ["#ifndef CREATE_GRAMMAR_HEADER",
             "#define CREATE_GRAMMAR_HEADER",
             "#include \"token.hpp\"",
             "#include \"cfg.hpp\"",
             "#include <vector>\n",
             "Grammar create_grammar() {",
             "Grammar g;\n"]

for l in raw:
    lhs = l.split("::=")[0].strip();
    productions = [i.strip() for i in l.split("::=")[1].split("|")]
    for p in productions:
        rhs = p.split();
        out_lines.append(create_production(lhs, rhs))

out_lines.append("\nreturn g;\n}")
out_lines.append("#endif\n")

with open(sys.argv[2], 'w') as out_file:
    out_file.write('\n'.join(out_lines))
