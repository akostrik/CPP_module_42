// 1) exécutez avec MutantStack
// 2) executez en remplaçant la MutantStack, par exemple par std::list

#include "MutantStack.hpp"

int main() {
  MutantStack<int> mstack;

  mstack.push(5);
  mstack.push(17);
  std::cout << mstack.top() << std::endl;
  mstack.pop();
  std::cout << mstack.size() << std::endl;
  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  mstack.push(0);

  for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
    std::cout << *it << std::endl;

  std::stack<int> s(mstack);

  return 0;
}