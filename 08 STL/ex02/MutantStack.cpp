#include "MutantStack.hpp"

MutantStack::MutantStack() : std::stack<T>() {}

MutantStack::MutantStack(const MutantStack& o) : std::stack<T>() { // std::stack<T>(o) ?
  *this = o;
}

MutantStack::~MutantStack() {}

MutantStack& MutantStack::operator=(const MutantStack& o) {
  std::copy(o.begin(), o.end(), this->begin()); // non itreable
  return *this;
}