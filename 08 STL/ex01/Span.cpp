#include "Span.hpp"

Span::Span(unsigned int N) : std::vector<unsigned int>() {
  _N  = N;
  i   = 0;
  min = UINT_MAX;
  max = 0;
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
  std::cout << "addNumber i = " << i << ", a = " << a << std::endl;
  if(i == _N)
    throw std::overflow_error("Span has no free space");
  this->push_back(a);
  if (min > a)
    min = a;
  if (max < a)
    max = a;
  i++;
}

unsigned int Span::shortestSpan() {
  if(i <= 1)
    throw std::exception();
  std::sort(this->begin(), this->end());
   // vector(const allocator_type& __a) _GLIBCXX_NOEXCEPT
  // v  ector(size_type __n, const allocator_type& __a = allocator_type())
  // vector(const vector& __x)
  // vector(vector&&) noexcept = default;
  // vector() = default;
  // vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
  // vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
  // vector(size_type __n, const value_type& __value,
  // vector(vector&& __rv, const allocator_type& __m, true_type) noexcept
  // vector(vector&& __rv, const allocator_type& __m, false_type)
  // vector(_InputIterator __first, _InputIterator __last,

  // std::transform(_copy.begin(), _copy.end() - 1, _copy.begin() + 1, _copy.begin(), [](int n1, int n2) { return n2 - n1; });
  // for (int i=0; i<2; i++)
  //  std::cout << _copy[i] << " ";
  unsigned int span = UINT_MAX;
                    return span;
            
}
  //std::unique_ptr<unsigned  int> ptr = queue.top();
  //unsigned int max = *this->pop(); // returns const unique_ptr<unsigned int>
  // you remove the elt, dereferencing it would result in undefined behavior

// unsigned int Span::longestSpan() {
//   if(this->empty() || this->size() < 2) // to test
//     throw std::exception();
//   return (_max - _min);
// }