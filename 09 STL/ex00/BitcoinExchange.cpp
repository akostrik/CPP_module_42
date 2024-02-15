#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(unsigned int N) {
	try {
		readFile("data.csv", ',');
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& o) {
  std::copy(o.begin(), o.end(), this->begin());
  return *this;
}

////////////////////////////////////////////
std::map<std::string, double> BitcoinExchange::readFile(std::string const filename, char const separator) {
	std::ifstream                 in(filename);
	std::map<std::string, double> m;
	std::string                   line;

	if (!in.is_open()) {
		throw std::exception(); // to see
	while (getline (in, line)) {
		std::split
		m.add() += line + "\n";
	}

	in.close();
	return m;
}


unsigned int BitcoinExchange::shortestBitcoinExchange() {
  std::cout << "not sorted  : ";
  for (std::vector<unsigned int>::iterator it = this->begin(); it != this->end(); it++)
    std::cout << *it << "  ";
  std::sort(this->begin(), this->end());                                                 // algo
  std::cout << std::endl << "sorted      : ";
  for (std::vector<unsigned int>::iterator it = this->begin(); it != this->end(); it++)
    std::cout << *it << "  ";

  std::vector<unsigned int> *BitcoinExchanges = new std::vector<unsigned int>(this->size());
  std::adjacent_difference(this->begin(), this->end(), BitcoinExchanges->begin());                 // numeric>
  std::rotate(BitcoinExchanges->begin(), BitcoinExchanges->begin() + 1, BitcoinExchanges->end());                        // algo
  BitcoinExchanges->pop_back();
  std::cout << std::endl << "BitcoinExchanges       : ";
  for (std::vector<unsigned int>::iterator it = BitcoinExchanges->begin(); it != BitcoinExchanges->end(); it++)
    std::cout << *it << "  ";
  std::cout << std::endl << std::endl;

  return *std::min_element(BitcoinExchanges->begin(), BitcoinExchanges->end());                               // algo
}