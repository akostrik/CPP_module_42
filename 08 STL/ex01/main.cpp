#include "Span.hpp"
#include <iostream>

int main() {
  Span s = Span(5);

  s.push(1);
  s.push(3);
  s.push(2);
  std::cout << "First = " << s.top() << ", size = " << s.size() << std::endl;
  s.pop();
  std::cout << "First = " << s.top() << ", size = " << s.size() << std::endl;

  // sp.addNumber(17);
  // sp.addNumber(9);
  // sp.addNumber(11);
  // std::cout << sp.shortestSpan() << std::endl; // 2
  // std::cout << sp.longestSpan()  << std::endl; // 14

  return 0;
}