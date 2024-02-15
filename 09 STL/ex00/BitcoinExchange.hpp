#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <algorithm>
# include <iostream>
# include <exception>
# include <climits>
# include <vector>
# include <list>
# include <iterator>
# include <functional>
# include <numeric>
# include <map>
# include <string>
# include <fstream>

class BitcoinExchange {
	private:
	std::map<std::string, double> data1;
	std::map<std::string, double> data2; // a float or a positive integer, between 0 and 1000
									BitcoinExchange();

	public:
								BitcoinExchange        (unsigned int N);
								BitcoinExchange        (const BitcoinExchange& o);
								~BitcoinExchange       ();
	BitcoinExchange&              operator=   (const BitcoinExchange& o);
	std::map<std::string, double> readFile(std::string const filename, char const separator);

};
#endif