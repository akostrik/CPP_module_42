#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cout << "Error: give a filename as the argument.\n";
    return 0;
  }
  try {
    BitcoinExchange b = BitcoinExchange();
    BitcoinExchange b2(b);
    b2.run(argv[1]);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}