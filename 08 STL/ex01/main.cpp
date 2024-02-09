#include "Span.hpp"
#include <iostream>
#define N 5

int main() {
  Span s                      = Span(N);
  std::vector<unsigned int> v = std::vector<unsigned int>();

  try {
    s.addNumber(7);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  v.push_back(5);
  v.push_back(10);
  v.push_back(2);
  v.push_back(15);
  v.push_back(20);
  try {
    s.addManyNumbers(*v.begin(), *v.end());
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << std::endl << "not sorted : ";
  for (const unsigned int& i : s) 
    std::cout << i << "  ";

  try {
    std::cout << std::endl << s.shortestSpan() << " (shortestSpan)" << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  try {
    std::cout << std::endl << s.longestSpan()  << " (longuestSpan)" << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}