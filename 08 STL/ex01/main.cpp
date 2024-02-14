#include "Span.hpp"
#include <iostream>
#include <list>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>


#define N 10 // -1

int main() {

  std::vector<unsigned int> v0;
  v0.push_back(5);
  v0.push_back(7);
  v0.push_back(9);
  v0.push_back(11);
  std::adjacent_difference(v0.begin(), v0.end(), v0.begin());
  std::cout << "INIT : ";
  for (std::vector<unsigned int>::iterator it = v0.begin(); it != v0.end(); it++)
    std::cout << *it << "  ";
  std::cout << std::endl;

  Span s = Span(N);

  try {
    s.addNumber(6);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  try {
    std::vector<unsigned int> v;
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