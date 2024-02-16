#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <iostream>
# include <map>
# include <string>
# include <fstream>
# include <stdlib.h> // strtod
# include <iomanip>
# include <stdexcept>
# include <limits>
// # include <regex> c++11
# include <regex.h>

// # include <algorithm>
// # include <exception>
// # include <iterator>
// # include <functional>
// # include <numeric>

# define DB_FILE "data.csv"

class BitcoinExchange : std::map<std::string, unsigned long long> {
	public:
								   BitcoinExchange();
								   BitcoinExchange        (const BitcoinExchange& o);
								   ~BitcoinExchange       ();
	BitcoinExchange& operator=   (const BitcoinExchange& o);
  void             run(std::string filename);
  bool             is_valid_date(std::string date);
  void             print_without_trailing_zeros(std::string date, unsigned long long n);
};

#endif