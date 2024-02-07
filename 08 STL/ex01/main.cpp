#include "Span.hpp"
#include <iostream>

int main() {
  Span s = Span(5);

  s.addNumber(1);
  s.addNumber(5);
  s.addNumber(2);
  std::cout << "top " << s.top() << ", size " << s.size() << ", longSpan  = " << s.longestSpan() << std::endl;

  return 0;
}