#include <regex>
#include <iostream>


int main(int argc, char const *argv[]) {
  std::regex re("\\s*'([^\\\\']|(\\\\[\\\\\'abfnrtv]))'\\s*");
  //            "\\s*'([^\\\\']|(\\\\[\\\\\'abfnrtv]))'\\s*"
  std::cout << std::regex_match("'a'", re) << '\n';
  std::cout << std::regex_match("'\\n'", re) << '\n';
  return 0;
}
