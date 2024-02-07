#include "Span.hpp"

Span::Span(unsigned int N) : _N(N){
  //_container = new std::multiset<unsigned int>();
}

Span::Span(const Span& o) {
  *this = o;
}

Span::~Span() {
  // delete[] _cont;
  // clear?
}

Span& Span::operator=(const Span& o) {
  // allocate memory ?
  //_cont = o.getContainer().copy();
  (void)o;
  return *this;
}

// std::priority_queue<unsigned int> Span::getCont() {
//   return _cont;
// }

////////////////////////////////////////////
void Span::addNumber(const unsigned int a) {
  // if(_cont.size() >=_N)
  //   throw std::overflow_error("Span has no more free spaces");
  //_cont.push(a);
  this->push(a);
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
//   if(_cont.empty() || _cont.count() <=2)
//     throw std::exception();
//   std::priority_queue<unsigned int> copy = _cont.copy();

//   return (_container[_container.count() - 1] - _container[0])
// }

	// if (this->_size < 2 || this->_vector.size() < 2) throw Span::SizeTooSmallException();
	// return *std::max_element(this->_vector.begin(), this->_vector.end())
	// 	- *std::min_element(this->_vector.begin(), this->_vector.end());