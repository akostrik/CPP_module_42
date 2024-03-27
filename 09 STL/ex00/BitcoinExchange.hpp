#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <iostream>
# include <map>
# include <string>
# include <fstream>
# include <stdlib.h>
# include <iomanip>
# include <stdexcept>
# include <limits>
# include <algorithm>
# include <regex.h>
# include <cmath>

# define DB_FILE "data.csv"

class BitcoinExchange : std::map<std::string, unsigned long long> {
  public:
                   BitcoinExchange ();
                   BitcoinExchange (const BitcoinExchange& o);
                   ~BitcoinExchange();
  BitcoinExchange& operator=       (const BitcoinExchange& o);
  void             run             (std::string filename);
};

#endif