// the type conversion must be solved using one specific type of casting
// non displayable characters shouldn’t be used as inputs

#include "ScalarConverter.hpp"

int main(int argc, char* argv[]) {
  ScalarConverter *c = new ScalarConverter();

  if (argc == 1)
    return (std::cout << "give one argument\n", 0);
  try {
    c->convert(argv[1]);
    std::cout << c << std::endl;
    std::cout << c->getCharV() << std::endl;
  }
  catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}
