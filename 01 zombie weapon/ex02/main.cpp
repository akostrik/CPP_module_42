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
  //std::cout << "address &(s[0])               " << &(s[0])      << std::endl;
  //std::cout << "address (void*)&s[0]          " << (void*)&s[0] << std::endl;
  std::cout << "address held by stringPTR     " << stringPTR    << std::endl;
  std::cout << "address held by stringREF     " << &stringREF   << std::endl;
  std::cout << "value s                       " << s            << std::endl;
  std::cout << "value pointed to by stringPTR " << *stringPTR   << std::endl;
  std::cout << "value pointed to by stringREF " << stringREF    << std::endl;

  return (0);
}

// output:

// address of s                  0x7ffe2c36fe10
// value s                       HI THIS IS BRAIN

// address held by stringPTR     0x7ffe2c36fe10 // holds the same address, points to the same string
// value pointed to by stringPTR HI THIS IS BRAIN

// address held by stringREF     0x7ffe2c36fe10
// value pointed to by stringREF HI THIS IS BRAIN

// address &(s[0])               HI THIS IS BRAIN (?)
// address (void*)&s[0]          0x55a2f8e71eb0
