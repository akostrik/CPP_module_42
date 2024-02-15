#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <iostream>
# include <map>
# include <string>
# include <fstream>
#include <stdlib.h> // strtod
// # include <algorithm>
// # include <exception>
// # include <iterator>
// # include <functional>
// # include <numeric>

# define DB_FILE "data.csv"

class BitcoinExchange : std::map<std::string, unsigned long long> {
	private:

	public:
								BitcoinExchange();
	// 							BitcoinExchange        (const BitcoinExchange& o);
	// 							~BitcoinExchange       ();
	// BitcoinExchange&              operator=   (const BitcoinExchange& o);

};
#endif