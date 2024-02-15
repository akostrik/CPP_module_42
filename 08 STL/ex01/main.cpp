#include "Span.hpp"
#include <iostream>
#include <list>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <string>
#include <sstream>

#define N 10

template < typename T > std::string my_to_string(const T& n) {
  std::ostringstream stm;
  stm << n;
  return stm.str();
}

bool is_unsigned_int(const std::string& s) {
  if (s.empty())
    return false;
  if (s.find_first_not_of("+0123456789") != s.npos)
    return false;
  return (s.compare(std::string("4294967295")) <= 0);
}

int main() {
  Span         s      = Span(1); // tmp // test 0
  std::string  N_str  = my_to_string(N);
  unsigned int N_real = 3; // tmp

  std::cout << "N_str  = " << N_str << std::endl;
  if (!is_unsigned_int(N_str)) {
    std::cout << "N sould be an insigned int" << std::endl;
    return 0;
  }

  N_real = strtoul(N_str.c_str(), NULL, 10);
  std::cout << "N_real = " << N_real << std::endl;
  if (N_real > s.max_size()) {
    std::cout << "N sould be less than " << s.max_size() << std::endl;
    return 0;
  }

  try {
    s = Span(N_real);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "here " << std::endl;
  try {
    s.addNumber(1);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "here " << std::endl;

  try {
    std::vector<unsigned int> v;
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    s.addNumber(v.begin(), v.end());
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  try {
    std::list<unsigned int> l;
    l.push_back(5);
    l.push_back(6);
    l.push_back(7);
    s.addNumber(l.begin(), l.end());
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