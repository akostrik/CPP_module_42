#include "Span.hpp"
#include <iostream>

int main() {
  Span s = Span(5);

  // try {
  //   s.addNumber(7);
  //   s.addNumber(5);
  //   s.addNumber(13);
  //   s.addNumber(10);
  //   s.addNumber(20);
  //   s.addNumber(25);
  // } catch (std::exception &e) {
  //   std::cout << e.what() << std::endl;
  // }

  std::vector<unsigned int> v = std::vector<unsigned int>();
  v.push_back(7);
  v.push_back(5);
  v.push_back(10);
  s.addManyNumbers(v.begin(), v.end());

  for (const int& i : s) 
    std::cout << i << "  ";
  std::cout << std::endl;

  std::cout << "shortestSpan = " << s.shortestSpan() << std::endl;
  std::cout << "longestSpan  = " << s.longestSpan() << std::endl;

  return 0;
}