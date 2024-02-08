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
  //_N = o._N; // 
  (void)o;
  return *this;
}

////////////////////////////////////////////
void Span::addNumber(unsigned int a) {
  std::cout << "addNumber(" << a << ")" << std::endl;
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
  if(size <= 1)
    throw std::exception();
  std::sort(this->begin(), this->end());
  std::vector<unsigned int> spans = std::vector<unsigned int>(size - 1);
  std::transform(this->begin(), this->end(), this->begin() + 1, spans.begin(), [](unsigned int n1, unsigned int n2) { return n2 - n1; });
  for (const int& i : spans) 
    std::cout << i << "  ";
  std::cout << std::endl;
  return *std::min_element(spans.begin(), spans.end());
}

unsigned int Span::longestSpan() {
  if(size < 2)
    throw std::exception();
  return (max - min);
}