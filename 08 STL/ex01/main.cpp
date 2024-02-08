#include "Span.hpp"
#include <iostream>

int main() {
  Span s = Span(5);

  s.addNumber(1);
  s.addNumber(5);
  s.addNumber(2);
  s.addNumber(10);
  s.addNumber(0);

  for (int i = 0; i < 5; i++)
    std::cout << s[i] << " ";
  std::cout << std::endl;

  std::sort(s.begin(), s.end());
  for (int i = 0; i < 5; i++)
    std::cout << s[i] << " ";
  std::cout << std::endl;
  // s.shortestSpan();
  // for (int i = 0; i < 3; i++)
  //   std::cout << s[i] << " ";
  // std::cout << std::endl;
  // std::sort(s.getArr().begin(), s.getArr().end());

//  for (const int& i : s.getArr()) {
//     std::cout << i << "  ";
//   }

    return 0;
  }