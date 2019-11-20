#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "lexer.hpp"


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
    cmpl::Lexer lx;
    std::vector<std::string> lexemes = lx.lex(str);
    for (size_t i = 0; i < lexemes.size(); i++) {
      std::cout << lexemes[i] << std::endl;
    }
  }

  return 0;
}
