#include <cctype>
#include <string>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <list>
#include <cstddef>
#include <iostream>

int	main()
{
  std::string s          = "HI THIS IS BRAIN";
  std::string *stringPTR = &s;
  std::string &stringREF = s;

  std::cout << "address of s                  " << &s           << std::endl;
  std::cout << "// address &(s[0])            " << &(s[0])      << std::endl;
  std::cout << "// address (void*)&s[0]       " << (void*)&s[0] << std::endl;
  std::cout << "address held by stringPTR     " << stringPTR    << std::endl;
  std::cout << "address held by stringREF     " << &stringREF   << std::endl;
  std::cout << "value s                       " << s            << std::endl;
  std::cout << "value pointed to by stringPTR " << *stringPTR   << std::endl;
  std::cout << "value pointed to by stringREF " << stringREF    << std::endl;

  return (0);
}
