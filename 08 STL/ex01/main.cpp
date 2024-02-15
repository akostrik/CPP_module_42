#include "Span.hpp"
#include <iostream>
#include <list>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>

#define N 7 // -1

int main() {
  Span s = Span(N);

  try {
    s.addNumber(1);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  try {
    std::vector<unsigned int> v;
    v.push_back(8);
    v.push_back(3);
    v.push_back(6);
    s.addNumber(v.begin(), v.end());
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  try {
    std::list<unsigned int> l;
    l.push_back(0);
    l.push_back(2);
    l.push_back(9);
    s.addNumber(l.begin(), l.end());
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  // to test exception:
  try {
    s.addNumber(2);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

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