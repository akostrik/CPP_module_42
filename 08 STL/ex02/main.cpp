// executez en remplaçant la MutantStack par std::list
// testes !
#include "MutantStack.hpp"
#include <list>

int main() {
  MutantStack<int> s;

  s.push(5);
  s.push(7);

  std::cout << "top = " << s.top() << ", stze = " << s.size() << std::endl;

  s.pop();
  std::cout << "top = " << s.top() << ", stze = " << s.size() << std::endl;
  s.push(3);
  s.push(5);
  s.push(8);
  s.push(4);

  for (MutantStack<int>::iterator it = s.begin(); it != s.end(); ++it)
    std::cout << *it << std::endl;

  std::stack<int> s2(s);
  std::cout << "top = " << s2.top() << ", stze = " << s2.size() << std::endl;

  return 0;
}