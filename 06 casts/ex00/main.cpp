// the type conversion must be solved using one specific type of casting
// non displayable characters shouldn’t be used as inputs

#include "ScalarConverter.hpp"

int main(int argc, char* argv[]) {

  if (argc == 1)
    return (std::cout << "give one argument\n", 0);
  try {
    ScalarConverter::convert(argv[1]);
  }
  catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}
