#include "Span.hpp"
#include <iostream>

int main() {
  Span s                      = Span(5);
  std::vector<unsigned int> v = std::vector<unsigned int>();

  try {
    s.addNumber(7);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  v.push_back(5);
  v.push_back(10);
  v.push_back(2);
  try {
    s.addManyNumbers(*v.begin(), *v.end());
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  // std::cout << "not sorted : ";
  // for (const unsigned int& i : s) 
  //   std::cout << i << "  ";
  // std::cout << std::endl;


  std::cout << s.longestSpan()  << " (longuestSpan)" << std::endl;
  std::cout << s.shortestSpan() << " (shortestSpan)" << std::endl;

  return 0;
}