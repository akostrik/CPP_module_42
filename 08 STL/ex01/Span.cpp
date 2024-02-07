#include "Span.hpp"

Span::Span(unsigned int N) : N(N), i(0), min(UINT_MAX), max (0) {
  arr = new unsigned int[N];
}

Span::Span(const Span& o) {
  *this = o;
}

Span::~Span() {
  // delete[] _arr;
}

Span& Span::operator=(const Span& o) {
  //_N = o._N; //
  (void)o;
  return *this;
}

unsigned int* Span::getArr() {
  return arr;
}

////////////////////////////////////////////
void Span::addNumber(const unsigned int a) {
  if(i == N - 1)
    throw std::overflow_error("Span has no free space");
  arr[i] = a;
  if (min > a)
    min = a;
  if (max < a)
    max = a;
  i++;
}

unsigned int Span::shortestSpan() {
  if(i <= 1)
    throw std::exception();
  std::sort(&arr[0], &arr[i - 1]);
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