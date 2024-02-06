#include "Span.hpp"

Span::Span(unsigned int N) : _N(N){
  _container = new std::multiset<unsigned int>();
}

Span::Span(const Span& o) {
  *this = o;
}

Span::~Span() {
  // delete[] _container;
  // clear?
}

Span& Span::operator=(const Span& o) {
  // allocate memory ?
  _container = o.getContainer().copy();
  return *this;
}

std::multiset<unsigned int> Span::getContainer() const {
  return _container;
}

////////////////////////////////////////////
void Span::addNumber(const unsigned int a) {
  if(_container.count(unsigned int) >=_N)
    throw std::exception();
  _container.insert(a);
}

// const unsigned int Span::shortestSpan() {
//   if(_container.count() <=2)
//     throw std::exception();
//   std::multiset copy = _container.copy();
//   copy.adjacent_difference();
//   copy[0] = _container[_container.count() - 1] - _container[0];
//   copy.replace_if();
//   return copy.min();
// }

// const unsigned int Span::longestSpan() {
//   if(_container.count() <=2)
//     throw std::exception();
//   return (_container[_container.count() - 1] - _container[0])
// }