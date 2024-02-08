#include "Span.hpp"
#include <iostream>

int main() {
  Span s = Span(5);

  s.addNumber(7);
  s.addNumber(5);
  s.addNumber(13);
  s.addNumber(10);
  s.addNumber(20);

  for (const int& i : s) 
    std::cout << i << "  ";
  std::cout << std::endl;

  std::cout << "shortestSpan = " << s.shortestSpan() << std::endl;
  std::cout << "longestSpan  = " << s.longestSpan() << std::endl;

  return 0;
}