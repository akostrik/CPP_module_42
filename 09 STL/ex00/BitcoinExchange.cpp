#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : std::map<std::string, unsigned long long>() {
	std::ifstream      db_file(DB_FILE);
	std::string        line;
  std::string        date;
  std::string        dollars;
  std::string        cents;
  unsigned long long value; // the price in cents

	if (!db_file.is_open())
		throw std::exception(); // !
  std::getline(db_file, line); // skip first line
 	while (getline (db_file, line)) {
    date    = line.substr(0, line.find(",")); // trim 
    dollars = line.substr(11, line.find(".") - line.find(",") - 1);
    cents   = line.substr(line.find(".") + 1, line.size() - line.find("."));
    value   = 100 * std::strtol(dollars.c_str(), NULL, 10);
    if (line.find(".") != std::string::npos && cents.size() == 2)
      value += std::strtol(cents.c_str(), NULL, 10);
    else if (line.find(".") != std::string::npos && cents.size() == 1)
      value += 10 * std::strtol(cents.c_str(), NULL, 10);
    this->insert(std::pair<std::string, unsigned long long>(date, value));
  }
	db_file.close();
}

// BitcoinExchange::~BitcoinExchange() {}

// BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& o) {
//   std::copy(o.begin(), o.end(), this->begin());
//   return *this;
// }

////////////////////////////////////////////
// std::map<std::string, double> BitcoinExchange::readFile(std::string const filename) {
// 	std::map<std::string, double> data2; // a float or a positive integer, between 0 and 1000
// 	return m;
// }