#include "easyfind.hpp"
//#include <array> C++11
#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>

template <typename T>
void test(T container, int n) {
  try                            { std::cout << *easyfind(container, n) << std::endl; }
  catch(const std::exception& e) { std::cout << "Value not found!" << std::endl; }
}

int main( void ) {
  std::vector<int> vector;
  vector.push_back(1);
  vector.push_back(2);
  test(vector, 2);
  test(vector, 3);

  return 0;
}