#include "Span.hpp"
#include <iostream>
#include <list>
#define N 6

int main() {
  Span s                   = Span(N);
  std::vector<unsigned int> v{5,10,15};
  std::list<unsigned int>   l{10,20,30};

  // try {
  //   s.addNumber(7);
  // } catch (std::exception &e) {
  //   std::cout << e.what() << std::endl;
  // }
  // std::cout << std::endl;

  std::cout << "1) v.begin() = " << *v.begin() << std::endl;
  try {
    s.addNumbers(v.begin(), v.end());
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << std::endl;


  /////////////////////////////////////////////////////////////
  std::cout << "1) list: ";
  for (std::list<unsigned int>::iterator it = l.begin() ; it != l.end(); it++)
    std::cout << *it << " ";
  std::cout << std::endl << std::endl;

  try {
    s.addNumbers(l.begin(), l.end());
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << std::endl;

  std::cout << std::endl << "not sorted : ";
  for (const unsigned int& i : s) // range  C++11
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