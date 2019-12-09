#include <string>
#include <vector>
#include "fsm_transitions.hpp"


FSMTransition::FSMTransition(size_t self, size_t next) {
  self_ = self;
  next_ = next;
}

size_t FSMTransition::attempt(char c) {
  if (accepts(c)) {
    return next_;
  }
  return SIZE_MAX;
}

size_t FSMTransition::self() {
  return self_;
}

size_t FSMTransition::next() {
  return next_;
}


bool AnyTransition::accepts(char c) {
  return true;
}

AnyTransition::AnyTransition(size_t self, size_t next)
  : FSMTransition(self, next) {
}


bool SingleTransition::accepts(char c) {
  return c == condition_;
}

SingleTransition::SingleTransition(size_t self, size_t next, char cond)
  : FSMTransition(self, next) {
  condition_ = cond;
}


bool IncludeTransition::accepts(char c) {
  return acceptable_.find(c) != std::string::npos;
}

IncludeTransition::IncludeTransition(size_t self, size_t next, std::string chars)
  :FSMTransition(self, next) {
  acceptable_ = chars;
}


bool ExcludeTransition::accepts(char c) {
  return unacceptable_.find(c) == std::string::npos;
}

ExcludeTransition::ExcludeTransition(size_t self, size_t next, std::string chars)
  :FSMTransition(self, next){
  unacceptable_ = chars;
}
