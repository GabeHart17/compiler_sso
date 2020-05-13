#ifndef SYMBOL_TABLE_HEADER
#define SYMBOL_TABLE_HEADER

#include <vector>
#include <map>
#include <string>
#include "token.hpp"


struct SymbolData {
  TokenType type;  // set to t_null to indicate symbol not found
  unsigned int location;
  SymbolData(TokenType t, unsigned int l): type(t), location(l) {}
  SymbolData(TokenType t): type(t), location(0) {}
  SymbolData(): type(TokenType::t_null), location(0) {}
  bool exists() { return type != TokenType::t_null; }
};


class SymbolTable {
private:
  typedef std::map<std::string, SymbolData> Scope;
  std::vector<Scope> table_;

public:
  SymbolTable() {}
  void push_scope();
  void pop_scope();
  bool add_symbol(std::string, SymbolData);  // returns false if insertion failed due to already existing symbol
  SymbolData find_symbol(std::string);
};


void SymbolTable::push_scope() {
  table_.push_back(Scope());
}

void SymbolTable::pop_scope() {
  table_.pop_back();
}

bool SymbolTable::add_symbol(std::string name, SymbolData dat) {
  if (table_.back().find(name) != table_.back().end()) {
    return false;
  }
  table_.back()[name] = dat;
  return true;
}

SymbolData SymbolTable::find_symbol(std::string name) {
  for (std::vector<Scope>::iterator it = table_.rbegin(); it != table_.rend(); it++) {
    Scope::iterator s = it->find(name);
    if (s != it->end()) {
      return *it;
    }
  }
  return SymbolData();
}


#endif
