// -340282346638528859811704183484516925440.0
// 340282346638528859811704183484516925440.0

// to verify:
// -340282346638528859811704183484516925440.00001
// 2147483647f
// 2147483647f
// 340282346638528859811704183484516925440.0
// .567f

// accept the use of implicit casts for promotion casts only

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
