// executez en remplaçant la MutantStack par std::list
// testes !
#include "MutantStack.hpp"
#include <list>

int main() {
  MutantStack<int> s;

  std::cout << "*** TEST push pop top size" << std::endl;
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
    std::cout << *it << " ";
  std::cout << std::endl;
  std::cout << "top = " << s.top() << ", stze = " << s.size() << std::endl;

  std::cout << "** TEST constructor MutantStack s2(s)" << std::endl;
  MutantStack<int> s2(s);
  std::cout << "top = " << s2.top() << ", stze = " << s2.size() << std::endl;
  for (MutantStack<int>::iterator it = s2.begin(); it != s2.end(); ++it)
    std::cout << *it << " ";
  std::cout << std::endl;

  std::cout << "*** TEST MutantStack s3 = s" << std::endl;
  MutantStack<int> s3 = s;
  std::cout << "top = " << s3.top() << ", stze = " << s3.size() << std::endl;
  for (MutantStack<int>::iterator it = s3.begin(); it != s3.end(); ++it)
    std::cout << *it << " ";
  std::cout << std::endl;

  // std::stack<int> s4(s);

  return 0;
}