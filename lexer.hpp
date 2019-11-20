#include "fsm.hpp"
#include <vector>
#include <string>


#ifndef LEXER_HEADER
#define LEXER_HEADER 1


namespace cmpl {

  class Lexer {
  private:
    cmpl::StringFSM state_machine_;

    // returns whether string was successfully accepted by the fsm
    bool consume_(std::string c) {
      return state_machine_.feed(c);
    }

  public:
    Lexer() {
      // TO DO: set up lexeme state machine
      for (int i = 0; i < 6; i++) {
        state_machine_.add_state(false);  // 0-5 are rejecting states
      }

      for (int i = 6; i < 18; i++) {
        state_machine_.add_state(true);  // 6-17 are accepting
      }

      std::string op_symbols("{}[]();,");
      for (int i = 0; i < op_symbols.length(); i++) {
        state_machine_.add_transition(0, 6, std::string(1, op_symbols[i]));
      }

      std::string letters("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
      std::string numbers("1234567890");

      // numeric literals
      for (size_t i = 0; i < numbers.length(); i++) {
        state_machine_.add_transition(0, 7, std::string(1, numbers[i]));
        state_machine_.add_transition(1, 8, std::string(1, numbers[i]));
      }
      state_machine_.add_transition(7, 9, std::string("f"));
      state_machine_.add_transition(8, 9, std::string("f"));
      state_machine_.add_transition(7, 1, std::string("."));

      // TODO
      // char literals
      // string literals

      // identifiers
      for (size_t i = 0; i < letters.length(); i++) {
        state_machine_.add_transition(0, 10, std::string(1, letters[i]));
        state_machine_.add_transition(10, 10, std::string(1, letters[i]));
      }
      for (size_t i = 0; i < numbers.length(); i++) {
        state_machine_.add_transition(10, 10, std::string(1, numbers[i]));
      }
      state_machine_.add_transition(0, 10, std::string("_"));
      state_machine_.add_transition(10, 10, std::string("_"));

      // operators
      state_machine_.add_transition(0, 17, std::string("&"));
      state_machine_.add_transition(17, 6, std::string("&"));
      state_machine_.add_transition(0, 16, std::string("|"));
      state_machine_.add_transition(16, 6, std::string("|"));
      state_machine_.add_transition(0, 11, std::string("="));
      state_machine_.add_transition(0, 12, std::string(">"));
      state_machine_.add_transition(0, 13, std::string("<"));
      state_machine_.add_transition(0, 14, std::string("+"));
      state_machine_.add_transition(0, 15, std::string("-"));
      state_machine_.add_transition(11, 6, std::string("="));
      state_machine_.add_transition(12, 6, std::string(">"));
      state_machine_.add_transition(13, 6, std::string("<"));
      state_machine_.add_transition(14, 6, std::string("+"));
      state_machine_.add_transition(15, 6, std::string("-"));
      state_machine_.add_transition(0, 11, std::string("!"));
      state_machine_.add_transition(0, 11, std::string("*"));
      state_machine_.add_transition(0, 11, std::string("/"));
      state_machine_.add_transition(0, 11, std::string("%"));
    }
    ~Lexer() {}

    //lexes a string, returning vector of lexemes
    std::vector<std::string> lex(std::string str) {
      std::vector<std::string> lexemes;
      std::string l;
      for (size_t i = 0; i < str.length(); i++) {
        if (consume_(std::string(1, str[i]))) {
          l.push_back(str[i]);
        } else if (!l.empty()) {
          lexemes.push_back(l);
          l.clear();
          i--;
        }
      }
      if (!l.empty()) {
        lexemes.push_back(l);
      }
      return lexemes;
    }
  };

} /* lexeme */


#endif
