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

AnyTransition::AnyTransition(size_t self, size_t next) {
  self_ = self;
  next_ = next;
}


bool SingleTransition::accepts(char c) {
  return c == condition_;
}

SingleTransition::SingleTransition(size_t self, size_t next, char cond) {
  condition_ = cond;
  self_ = self;
  next_ = next;
}


bool IncludedTransition::accepts(char c) {
  return acceptable_.find(c) != std::string::npos;
}

IncludedTransition::IncludedTransition(size_t self, size_t next, std::string chars) {
  self_ = self;
  next_ = next;
  acceptable_ = chars;
}


bool ExcludedTransition::accepts(char c) {
  return unacceptable_.find(c) == std::string::npos;
}

ExcludedTransition::ExcludedTransition(size_t self, size_t next, std::string chars) {
  self_ = self;
  next_ = next;
  unacceptable_ = chars;
}
