#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "tokenizer.hpp"
#include "token.hpp"


int main(int argc, char const *argv[]) {


  if (argc < 2) {
    std::cout << "ERROR: specify file as second argument" << std::endl;
  } else {
    std::stringstream in_stream;
    std::ifstream infile(argv[1]);
    if (!infile) {
      std::cout << "ERROR: unable to open " << argv[1] << std::endl;
    }

    while (infile) {
      std::string s;
      std::getline(infile, s);
      in_stream << s << '\n';
    }

    std::string str = in_stream.str();
    Tokenizer tk;
    std::vector<Token> tokens = tk.tokenize(str);
    for (Token t : tokens) {
      std::cout << (int) t.get_type() << ":\t" << t.get_lexeme() << '\n';
    }
  }

  return 0;
}
