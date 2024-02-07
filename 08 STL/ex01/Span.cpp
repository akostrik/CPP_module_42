#include "Span.hpp"

Span::Span(unsigned int N) : _N(N), _min(UINT_MAX), _max(0) {}

Span::Span(const Span& o) {
  *this = o;
}

Span::~Span() {}

Span& Span::operator=(const Span& o) {
  _N = o._N; //
  return *this;
}

////////////////////////////////////////////
void Span::addNumber(const unsigned int a) {
  if(this->size() >=_N) // empty ?
    throw std::overflow_error("Span has no free space");
  this->push(a);
  if (_min > a)
    _min = a;
  if (_max < a)
    _max = a;
}

unsigned int Span::shortestSpan() {
  if(this->empty() || this->size() < 2) //
    throw std::exception();
  std::vector<unsigned int> _copy(this);
  //  vector(const allocator_type& __a) _GLIBCXX_NOEXCEPT
  // vector(size_type __n, const allocator_type& __a = allocator_type())
  //  vector(const vector& __x)
  // vector(vector&&) noexcept = default;
  // vector(vector&&) noexcept = default;
  //  vector() = default;
  // vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
  // vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
  // vector(size_type __n, const value_type& __value,
  //  vector(vector&& __rv, const allocator_type& __m, true_type) noexcept
  //  vector(vector&& __rv, const allocator_type& __m, false_type)
  //         vector(_InputIterator __first, _InputIterator __last,
  //std::transform(_copy.begin(), _copy.end() - 1, _copy.begin() + 1, _copy.begin(), [](int n1, int n2) { return n2 - n1; });
  //for (int i=0; i<2; i++)
  //  std::cout << _copy[i] << " ";
  unsigned int span = UINT_MAX;
                    return span;
            
}
  //std::unique_ptr<unsigned  int> ptr = queue.top();
  //unsigned int max = *this->pop(); // returns const unique_ptr<unsigned int>
  // you remove the elt, dereferencing it would result in undefined behavior

unsigned int Span::longestSpan() {
  if(this->empty() || this->size() < 2) // to test
    throw std::exception();
  return (_max - _min);
}