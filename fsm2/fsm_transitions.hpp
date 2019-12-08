#include <vector>
#include <string>


#ifndef FSM_TRANSITIONS_HEADER
#define FSM_TRANSITIONS_HEADER


class FSMTransition {
private:
  virtual bool accepts(char c) {
    return false;
  }
protected:
  size_t self_;  // index of state to which this transition belongs
  size_t next_;  // index of next state

public:
  FSMTransition(size_t, size_t);
  ~FSMTransition();
  size_t self();
  size_t next();
  size_t attempt(char c);
};


class AnyTransition : public FSMTransition {
private:
  bool accepts(char);

public:
  AnyTransition(size_t, size_t);
};


class SingleTransition : public FSMTransition {
private:
  char condition_;
  bool accepts(char);

public:
  SingleTransition(size_t, size_t, char);
};


class IncludeTransition : public FSMTransition {
private:
  std::string acceptable_;
  bool accepts(char);

public:
  IncludeTransition(size_t, size_t, std::string);
};


class ExcludeTransition : public FSMTransition {
private:
  std::string unacceptable_;
  bool accepts(char);

public:
  ExcludeTransition(size_t, size_t, std::string);
};


#endif /* end of include guard: FSM_TRANSITIONS_HEADER */
