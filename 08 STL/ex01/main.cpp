#include "Span.hpp"
#include <iostream>
#include <list>
#define N 6

int main() {
  Span s                   = Span(N);
  std::vector<unsigned int> v{1,2,7};
  std::list<unsigned int>   l{4,88,6};

  // try {
  //   s.addNumber(7);
  // } catch (std::exception &e) {
  //   std::cout << e.what() << std::endl;
  // }
  // std::cout << std::endl;

  std::cout << "1) v.begin() = " << *v.begin() << std::endl;
  try {
    s.addNumber(*v.begin(), *v.end());
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << std::endl;


  /////////////////////////////////////////////////////////////
  std::cout << "1) l.begin()     = " << *l.begin() << std::endl;
  std::cout << "1) list: ";
  for (std::list<unsigned int>::iterator it = l.begin() ; it != l.end(); it++)
    std::cout << *it << " ";
  std::cout << std::endl << std::endl;

  try {
    std::cout << "call addMany(" << *l.begin() << ", " << *l.end() << ")\n";
    s.addNumber(*l.begin(), *l.end());
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << std::endl;

  std::cout << std::endl << "not sorted : ";
  for (const unsigned int& i : s) // range  C++11
    std::cout << i << "  ";

  // try {
  //   std::cout << std::endl << s.shortestSpan() << " (shortestSpan)" << std::endl;
  // } catch (std::exception &e) {
  //   std::cout << e.what() << std::endl;
  // }
  // try {
  //   std::cout << std::endl << s.longestSpan()  << " (longuestSpan)" << std::endl;
  // } catch (std::exception &e) {
  //   std::cout << e.what() << std::endl;
  // }

  return 0;
}