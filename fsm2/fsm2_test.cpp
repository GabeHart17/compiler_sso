#include "fsm2.hpp"
#include "fsm_transitions.hpp"
#include <iostream>
#include <string>

int main(int argc, char const *argv[]) {
  FSM2<int> f2(5);
  /*
  f2.add_state(10);
  f2.add_state(42);
  f2.add_transition(new AnyTransition(0, 1));
  f2.add_transition(new SingleTransition(1, 2, 'z'));
  f2.add_transition(new IncludedTransition(2, 0, std::string("abc")));
  f2.consume('d');
  f2.consume('z');
  f2.consume('q');
  f2.consume('a');
  */
  return 0;
}
