#include "Span.hpp"
#include <iostream>
#include <list>
#define N 10 // -1

int main() {
  Span s = Span(N);

  try {
    s.addNumber(6);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  try {
    std::vector<unsigned int> v; // v{5,6,7} c++ 11
    v.push_back(5);
    v.push_back(8);
    v.push_back(7);
    s.addNumber(v.begin(), v.end());
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  // try {
  //   std::list<unsigned int> l;
  //   l.push_back(1);
  //   l.push_back(2);
  //   l.push_back(3);
  //   s.addNumber(l.begin(), l.end());
  // } catch (std::exception &e) {
  //   std::cout << e.what() << std::endl;
  // }

  // // to test exception:
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