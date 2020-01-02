# compiler_sso
A bare-bones compiler for a subset of C.

This compiler is not intended to be maximally efficient, nor to support the entirety of ANSI C. Rather, it is intended as an exploration of the different steps involved in making a compiler.

**Supported features:**
- variables (see supported types)
- casting
- arithmetic and bitwise operations
- function definition
- arrays
- pointers
- conditionals
- loops (for and while)
- increment and decrement operators
- text output to stdout

**Variable types:**
- bool
- char
- int
- float
- strings (as null terminated char arrays)

**If time features:**
- Ternary expressions
- Switch statements
- Other sizes of integral types
- Augmented assignment operators
- Preprocessor

**Excluded features:**
- Structs
- Function pointers
- Comma operator
