#include "Span.hpp"
#include <iostream>
#include <list>
#define N 6

int main() {
  Span s = Span(N);

  try {
    s.addNumber(6);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  try {
    std::vector<unsigned int> v{5,6,7};
    s.addNumbers(v.begin(), v.end());
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  try {
    std::list<unsigned int>   l{1,4,9};
    s.addNumbers(l.begin(), l.end());
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  // tester exception:
  // try {
  //   s.addNumber(2);
  // } catch (std::exception &e) {
  //   std::cout << e.what() << std::endl;
  // }

  std::cout << "not sorted : ";
  for (std::vector<unsigned int>::iterator it = s.begin(); it != s.end(); it++)
    std::cout << *it << "  ";

  try {
    std::cout << std::endl << s.shortestSpan() << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  try {
    std::cout << s.longestSpan()  << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}