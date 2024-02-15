// Vous pouvez avoir recours à quasi l’ensemble de la bibliothèque standard. 
// Donc plutôt que de rester en terrain connu, 
// essayez d’utiliser le plus possible les versions C++ des fonctions C dont vous avec l’habitude

#include "Span.hpp"
#include <iostream>
#include <list>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <string>
#include <sstream>

#define N 4611686018427387903

template < typename T > std::string my_to_string(const T& n) {
  std::ostringstream stm;
  stm << n;
  return stm.str();
}

bool is_unsigned_int(const std::string& s) {
  if (!s.empty() && s.find_first_not_of("+0123456789") == s.npos && strtoul(s.c_str(), NULL, 10) <= s.max_size()) 
    return true;
  std::cout << "N = " << N << std::endl << "N sould be an int in [0, " << s.max_size() << "]" << std::endl;
  return false;
}

int main() {
  Span         s      = Span(0); // tmp
  std::string  N_str  = my_to_string(N);
  long long    N_real;

  if (!is_unsigned_int(N_str))
    return 0;

  N_real = strtoul(N_str.c_str(), NULL, 10);
  try {
    s = Span(N_real);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  try {
    s.addNumber(1);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

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