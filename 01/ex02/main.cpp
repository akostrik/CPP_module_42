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
  std::string stringREF  = s;

  std::cout << "The memory address of s              " << &s         << std::endl;
  std::cout << "The memory address held by stringPTR " << stringPTR  << std::endl;
  std::cout << "The memory address held by stringREF " << &stringREF  << std::endl;
  std::cout << "The value of the string variable     " << s          << std::endl;
  std::cout << "The value pointed to by stringPTR    " << *stringPTR << std::endl;
  std::cout << "The value pointed to by stringREF    " << stringREF << std::endl;

  return (0);
}
