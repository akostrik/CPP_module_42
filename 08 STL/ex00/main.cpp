#include "easyfind.hpp"
#include <vector>
#include <deque>
#include <list>
#include <iostream>

template <typename T>
void test(T container, int n) {
  try                            { std::cout << *easyfind(container, n) << std::endl; }
  catch(const std::exception& e) { std::cout << "Value not found!"      << std::endl; }
}

int main( void ) {
  std::vector<int> vector;
  vector.push_back(1);
  vector.push_back(2);
  test(vector, 2);
  test(vector, 3);

  std::deque<int> deque;
  deque.push_back(1);
  deque.push_back(2);
  test(deque, 2);
  test(deque, 3);

  std::list<int> list;
  list.push_back(1);
  list.push_back(2);
  test(list, 2);
  test(list, 3);

  return 0;
}