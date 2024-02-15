#include "Span.hpp"

Span::Span(unsigned int N) : std::vector<unsigned int>() {
  _N   = N;
  min  = UINT_MAX;
  max  = 0;
}

Span::Span(const Span& o) : std::vector<unsigned int>() {
  *this = o;
}

Span::~Span() {}

Span& Span::operator=(const Span& o) {
  std::copy(o.begin(), o.end(), this->begin());
  _N   = o._N;
  min  = o.min;
  max  = o.max;
  return *this;
}

////////////////////////////////////////////
void Span::addNumber(unsigned int a) {
  if(this->size() >= _N)
    throw std::overflow_error("Span has no free space");
  this->push_back(a);
  if (min > a)
    min = a;
  if (max < a)
    max = a;
}

unsigned int Span::shortestSpan() {
  if(this->size() < 2)
    throw std::exception();

  std::cout << "not sorted  : ";
  for (std::vector<unsigned int>::iterator it = this->begin(); it != this->end(); it++)
    std::cout << *it << "  ";
  std::sort(this->begin(), this->end());                                                 // algo
  std::cout << std::endl << "sorted      : ";
  for (std::vector<unsigned int>::iterator it = this->begin(); it != this->end(); it++)
    std::cout << *it << "  ";

  std::vector<unsigned int> *spans = new std::vector<unsigned int>(this->size());
  std::adjacent_difference(this->begin(), this->end(), spans->begin());                 // <numeric>
  std::rotate(spans->begin(), spans->begin() + 1, spans->end());                        // algo
  spans->pop_back();
  std::cout << std::endl << "spans       : ";
  for (std::vector<unsigned int>::iterator it = spans->begin(); it != spans->end(); it++)
    std::cout << *it << "  ";
  std::cout << std::endl << std::endl;

  unsigned int ret = *std::min_element(spans->begin(), spans->end());                   // algo
  delete spans;
  return ret;
}

unsigned int Span::longestSpan() {
  if(this->size() < 2)
    throw std::exception();
  return (max - min);
}