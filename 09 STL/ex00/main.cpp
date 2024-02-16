#include "BitcoinExchange.hpp"

int main() {
  BitcoinExchange b = BitcoinExchange();
  try {
    b.run("input.txt"); // arg
	 } catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
  return 0;
}