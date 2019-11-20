#include <vector>
#include <string>


#ifndef FSM2_HEADER
#define FSM2_HEADER 1


namespace cmpl {

  class FSMTransition {
  private:
    FSMState* to_;

    virtual bool accepts(char c);

  public:
    FSMTransition(FSMState* next) {
      to_ = next;
    }

    ~FSMTransition() {}

    virtual FSMState* attempt(char c) {
      if (accepts(c)) {
        return to_;
      }
      return nullptr;
    }
  };


  class FSMState {
  private:
    std::vector<FSMTransition*> transitions_;

  public:
    FSMState() {

    }
     ~FSMState();

    void add_transition(FSMTransition* t) {
      transitions_.push_back(t);
    }

    FSMState* consume(char c) {
      FSMState* next = nullptr;
      for (size_t i = 0; i < transitions_.length(); i++) {
        next = transitions_[i].attempt(c);
        if (next != nullptr) {
          return next;
        }
      }
      return nullptr;
    }
  };




} /* cmpl */


#endif
