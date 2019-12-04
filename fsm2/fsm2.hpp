#include <vector>
#include <string>
#include "fsm_transitions.hpp"


#ifndef FSM2_HEADER
#define FSM2_HEADER

template <class T>
class FSMState {
private:
  std::vector<FSMTransition*> transitions_;
  T value_;

public:
  FSMState(T val) {
    value_ = val;
  }

  ~FSMState() {
    for (size_t i = 0; i < transitions_.size(); i++) {
      delete transitions_[i];
    }
  }

  T value() {
   return value_;
  }

  void add_transition(FSMTransition* t) {
    transitions_.push_back(t);
  }

  size_t next(char c) {  // index of next state when transitioning on c
    size_t next = SIZE_MAX; // SIZE_MAX returned if no transition
    for (size_t i = 0; i < transitions_.size(); i++) {
      next = transitions_[i] -> attempt(c);
    }
    return next;
  }
};



template <class T>
class FSM2 {
private:
  std::vector<FSMState<T>*> states_;
  FSMState<T>* current_;
  FSMState<T>* start_;

public:
  FSM2 (T start_val) {
    add_state(start_val);
    start_ = states_[0];
    current_ = start_;
  }

  ~FSM2 () {
    for (size_t i = 0; i < states_.size(); i++) {
      delete states_[i];
    }
  }

  void reset() {  // resets to start state
    current_ = start_;
  }
  void add_state(T val) {
    FSMState<T>* fs = new FSMState<T>(val);
    states_.push_back(fs);
  }

  void add_transition(FSMTransition* t) {
    states_[t -> self()] -> add_transition(t);
  }

  T poll() {  // returns value of current state
    return current_.value();
  }

  bool consume(char c) {  // returns whether transition was successful
    size_t next = current_ -> next(c);
    if (next != SIZE_MAX) {
      current_ = states_[next];
      return true;
    } else {
      reset();
      return false;
    }
  }
};



#endif
