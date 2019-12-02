#include <vector>
#include <string>


#ifndef FSM2_HEADER
#define FSM2_HEADER


namespace cmpl {


  template <class T>
  class FSM2 {
  private:
    std::vector<FSMState*> states_;
    FSMState* current_;
    FSMState* start_;

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

    FSMState* operator[] (const size_t& index) {
      return states_[index];
    }

    void reset() {  // resets to start state
      current_ = start_;
    }

    void add_state(T val) {
      FSMState* fs = new FSMState<T>(val);
      states_.push_back(fs);
    }

    void add_transition(FSMTransition* t, const size_t& from) {
      states_p[from].add_transition(t);
    }

    T poll() {  // returns value of current state
      return current_.value();
    }

    bool consume(char c) {  // returns whether transition was successful
      FSMState* next = current_.next(c);
      if (next != nullptr) {
        current_ = next_;
        return true;
      } else {
        reset();
        return false;
      }
    }
  };


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

    FSMState* next(char c) {  // pointer to next state when transitioning on c
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


  class FSMTransition {
  private:
    FSMState* to_;

    virtual bool accepts(char c) {
      return false;
    }

  public:
    FSMTransition(FSMState* next) {
      to_ = next;
    }

    ~FSMTransition();

    FSMState* attempt(char c) {
      if (accepts(c)) {
        return to_;
      }
      return nullptr;
    }
  };


  class AnyTransition : public FSMTransition {
  private:
    bool accepts(char c) {
      return true;
    }
  };


  class SingleTransition : public FSMTransition {
  private:
    char condition_;

    bool accepts(char c) {
      return c == condition_;
    }

  public:
    CharTransition(FSMState* next, char cond) {
      condition_ = cond;
      to_ = next;
    }
  };


  class IncludedTransition : public FSMTransition {
  private:
    std::string acceptable_;

    bool accepts(char c) {
      return acceptable_.find(c) != std::string::npos;
    }
  public:
    IncludedTransition(FSMState* next, std::string chars) {
      to_ = next;
      acceptable_ = chars;
    }
  };


  class ExcludedTransition : public FSMTransition {
  private:
    std::string unacceptable_;

    bool accepts(char c) {
      return unacceptable_.find(c) == std::string::npos;
    }
  public:
    ExcludedTransition(FSMState* next, std::string chars) {
      to_ = next;
      unacceptable_ = chars;
    }
  };

} /* cmpl */


#endif
