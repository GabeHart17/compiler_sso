#include <vector>
#include <string>


#ifndef FSM2_HEADER
#define FSM2_HEADER 1


namespace cmpl {


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

    FSMState* consume(char c) {ccept
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
