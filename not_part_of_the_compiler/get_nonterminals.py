"""
same file spec as grammar generator
retrieves all nonterminals
"""

import sys

with open(sys.argv[1]) as f:
    lines = [i for i in f.readlines() if i.strip()]

for l in lines:
    print(l.split(":=")[0].strip() + ',')
