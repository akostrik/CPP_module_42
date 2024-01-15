// -340282346638528859811704183484516925440.00001
// .567f !

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
