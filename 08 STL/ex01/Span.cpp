#include "Span.hpp"

Span::Span(unsigned int N) : std::vector<unsigned int>() {
  _N   = N;
  size = 0;
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
  size = o.size;
  min  = o.min;
  max  = o.max;
  return *this;
}

////////////////////////////////////////////
void Span::addNumber(unsigned int a) {
  if(size == _N)
    throw std::overflow_error("Span has no free space");
  this->push_back(a);
  if (min > a)
    min = a;
  if (max < a)
    max = a;
  size++;
}

unsigned int Span::shortestSpan() {
  if(size < 2)
    throw std::exception();

  std::sort(this->begin(), this->end());
  std::cout << "sorted     : ";
  for (std::vector<unsigned int>::iterator it = this->begin(); it != this->end(); it++)
    std::cout << *it << "  ";

  std::vector<unsigned int> rotatedCopy = *this;
  std::rotate(rotatedCopy.begin(),rotatedCopy.begin() + 1,rotatedCopy.end());

  std::transform(this->begin(), this->end(), rotatedCopy.begin(), rotatedCopy.begin(), [](unsigned int n1, unsigned int n2) { return n2 - n1; });
  rotatedCopy.pop_back();

  std::cout << std::endl << "spans      : ";
  for (std::vector<unsigned int>::iterator it = rotatedCopy.begin(); it != rotatedCopy.end(); it++)
    std::cout << *it << "  ";
  std::cout << std::endl << std::endl;

  return *std::min_element(rotatedCopy.begin(), rotatedCopy.end());
}

unsigned int Span::longestSpan() {
  if(size < 2)
    throw std::exception();
  return (max - min);
}