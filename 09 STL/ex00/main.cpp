#include "BitcoinExchange.hpp"
// 2012-01-11 | -1
// 2001-42-42
// 2012-01-11 | 2147483648
// 12-01-11 | 1
// 2009-04-41 | 1
// 2008-04-01 | 1

int main() {
  BitcoinExchange b = BitcoinExchange();
  try {
    b.run("input.txt"); // arg
	 } catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
  return 0;
}