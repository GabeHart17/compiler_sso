#include <vector>
#include <map>
#include <string>

#ifndef FSM_HEADER
#define FSM_HEADER 1


namespace cmpl {

  // an fsm state
  struct State {
    bool accepting;

    // string transition, unsigned int index of next state
    std::map<std::string, size_t> transitions;
  };

  // an fsm with string transitions
  class StringFSM {
  private:
    std::vector<State*> states_;
    // first element is starting state
    size_t start_ = 0;
    // index of current state
    size_t current_ = 0;

  public:
    StringFSM() {
    }

    ~StringFSM()  {
      for (int i = 0; i < states_.size(); i++) {
        delete states_[i];
      }
    }

    // add a state to the fsm
    void add_state(bool accepting) {
      State* s = new State;
      s -> accepting = accepting;
      states_.push_back(s);
    }

    // add a transition with condition
    void add_transition(size_t state_from, size_t state_to, std::string condition) {
      (states_[state_from] -> transitions)[condition] = state_to;
    }

    // resets to starting state
    void reset() {
      current_ = start_;
    }

    // checks if in accepting state without reseting
    bool poll() {
      return states_[current_] -> accepting;
    }

    // tests if in accepting state, then resets
    bool test() {
      bool res = poll();
      reset();
      return res;
    }

    // gives a string to the fsm, attempts to transition, resets if failure
    // returns whether attempt was successful
    bool feed(std::string s) {
      if ((states_[current_] -> transitions).count(s) != 0) {
        current_ = (states_[current_] -> transitions).at(s);
        return true;
      } else {
        reset();
        return false;
      }
    }

    // returns whether the fsm is in its starting state
    bool unaltered() {
      return current_ == start_;
    }
  };

} /* cmpl */


#endif
