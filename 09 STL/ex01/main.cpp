#include "RPN.hpp"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cout << "Error: give one argument.\n";
    return 0;
  }
  try {
    RPN b = RPN(argv[1]);
    RPN b2 = b;
    b2.run();
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}