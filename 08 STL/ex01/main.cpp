#include "Span.hpp"
#include <iostream>

int main() {
  Span s = Span(0);

  s.addNumber(1);
  s.addNumber(5);
  s.addNumber(2);
  std::cout << s.getArr()[0] << " " << s.getArr()[1] << " " << s.getArr()[2] << ", span = " << s.shortestSpan() << std::endl;

  for (int i = 0; i < 3; i++) {
    std::cout << s.getArr()[i] << " ";
  }

//  for (const int& i : s.getArr()) {
//     std::cout << i << "  ";
//   }

  return 0;
}