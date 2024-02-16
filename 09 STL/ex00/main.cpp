#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cout << "Error: give a filename as the argument\n";
    return 0;
  }
  try {
    BitcoinExchange b = BitcoinExchange();
    b.run(argv[1]);
	 } catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
  return 0;
}

/*
HEAP SUMMARY:
==2178601==     in use at exit: 4,378,700 bytes in 14,843 blocks
==2178601==   total heap usage: 21,099 allocs, 6,256 frees, 5,091,858 bytes allocated
==2178601== 
==2178601== LEAK SUMMARY:
==2178601==    definitely lost: 106,080 bytes in 442 blocks
==2178601==    indirectly lost: 4,272,620 bytes in 14,401 blocks
*/