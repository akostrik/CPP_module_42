// executez en remplaçant la MutantStack par std::list
#include "MutantStack.hpp"
#include <list>

int main() {
  MutantStack<int> s;

  std::cout << "*** TEST push() pop() top() size()" << std::endl;
  s.push(1);
  s.push(2);
  std::cout << "top = " << s.top() << ", stze = " << s.size() << std::endl;
  s.pop();
  std::cout << "top = " << s.top() << ", stze = " << s.size() << std::endl;
  s.push(3);
  s.push(4);
  s.push(5);
  for (MutantStack<int>::iterator it = s.begin(); it != s.end(); it++)
    std::cout << *it << " ";
  std::cout << std::endl;
  std::cout << "top = " << s.top() << ", stze = " << s.size() << std::endl;

  std::cout << "** TEST constructor MutantStack s2(s)" << std::endl;
  MutantStack<int> s2(s);
  std::cout << "top = " << s2.top() << ", stze = " << s2.size() << std::endl;
  for (MutantStack<int>::iterator it = s2.begin(); it != s2.end(); it++)
    std::cout << *it << " ";
  std::cout << std::endl;

  std::cout << "*** TEST MutantStack s3 = s" << std::endl;
  MutantStack<int> s3 = s;
  std::cout << "top = " << s3.top() << ", stze = " << s3.size() << std::endl;
  for (MutantStack<int>::iterator it = s3.begin(); it != s3.end(); it++)
    std::cout << *it << " ";
  std::cout << std::endl;

  std::cout << "*** TEST list" << std::endl;
  std::list<int> l;
  l.push_front(1);
  l.push_front(2);
  std::cout << "top = " << l.front() << ", stze = " << l.size() << std::endl;
  l.pop_front();
  std::cout << "top = " << l.front() << ", stze = " << l.size() << std::endl;
  l.push_front(3);
  l.push_front(4);
  l.push_front(5);
  for (std::list<int>::reverse_iterator it = l.rbegin(); it != l.rend(); it++)
    std::cout << *it << " ";
  std::cout << std::endl;
  std::cout << "top = " << l.front() << ", stze = " << l.size() << std::endl;

  return 0;
}