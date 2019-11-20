#include "fsm.hpp"
#include <iostream>
#include <string>

int main(int argc, char const *argv[]) {
  cmpl::StringFSM my_fsm;
  my_fsm.add_state(false);
  my_fsm.add_state(false);
  my_fsm.add_state(true);
  my_fsm.add_transition(0, 1, std::string("a"));
  my_fsm.add_transition(1, 1, std::string("b"));
  my_fsm.add_transition(1, 2, std::string("c"));
  std::cout << my_fsm.poll() << std::endl;
  std::cout << my_fsm.feed(std::string("a")) << std::endl;
  std::cout << my_fsm.test() << std::endl;
  my_fsm.feed(std::string("a"));
  my_fsm.feed(std::string("b"));
  my_fsm.feed(std::string("c"));
  std::cout << my_fsm.poll() << '\t' << my_fsm.test() << std::endl;
  std::cout << my_fsm.feed(std::string("b")) << std::endl;
  my_fsm.feed(std::string("a"));
  my_fsm.feed(std::string("b"));
  my_fsm.feed(std::string("b"));
  my_fsm.feed(std::string("b"));
  my_fsm.feed(std::string("c"));
  std::cout << my_fsm.test() << std::endl;
  my_fsm.reset();
  return 0;
}
