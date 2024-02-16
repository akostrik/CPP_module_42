#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : std::map<std::string, unsigned long long>() {
// modify "input.csv"
	std::ifstream      in(DB_FILE);
	std::string        line;
  std::string        date;
  std::string        dollars;
  std::string        cents;
  unsigned long long value; // the price in cents

	if (!in.is_open())
		throw std::exception(); // !
  std::getline(in, line); // skip first line
 	while (getline (in, line)) {
    date    = line.substr(0, line.find(",")); // trim
    date.erase(date.find_last_not_of(" \n\r\t") + 1);
    dollars = line.substr(11, line.find(".") - line.find(",") - 1);
    dollars.erase(dollars.find_last_not_of(" \n\r\t") + 1);
    cents   = line.substr(line.find(".") + 1, line.size() - line.find("."));
    cents.erase(cents.find_last_not_of(" \n\r\t")+1);
    value   = 100 * std::strtol(dollars.c_str(), NULL, 10);
    if (line.find(".") != std::string::npos && cents.size() == 2)
      value += std::strtol(cents.c_str(), NULL, 10);
    else if (line.find(".") != std::string::npos && cents.size() == 1)
      value += 10 * std::strtol(cents.c_str(), NULL, 10);
    this->insert(std::pair<std::string, unsigned long long>(date, value));
    // for(map<std::string, unsigned long long>::const_iterator it = this->begin(); it != this->end(); ++it)
    //   std::cout << it->first << " " << it->second << "\n";
  }
	in.close();
}

// BitcoinExchange::BitcoinExchange(const BitcoinExchange& o) : std::map<std::string, unsigned long long>() {
//   *this = o;
// }

BitcoinExchange::~BitcoinExchange() {}

// BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& o) {
//   std::copy(o.begin(), o.end(), this->begin());
//   return *this;
// }

////////////////////////////////////////////
// handle possible errors with an appropriate error message
// use an empty file
// a file with errors (a basic example exists in the subject)
// a wrong date
// run the prog with input.csv as parameter 
// if the date not exist in your DB, use the closest date contained in your DB, the lower date, not the upper one
void BitcoinExchange::run(std::string filename) {
	std::ifstream in("input.txt"); // in(filename);
  (void)filename;
	std::string   line;
  std::string   date;
  std::string   value_str;
  double        value;

  // if all keys are considered to go before k
  std::map<std::string, unsigned long long>::iterator upper = this->lower_bound("2011-01-08");
  std::map<std::string, unsigned long long>::iterator lower = --upper;
  std::cout << "lower 2011-01-08 : " << lower->first << " " << lower->second << std::endl;
	if (!in.is_open())
		throw std::exception(); // !
  std::getline(in, line); // skip first line
 	while (getline (in, line)) {
    date      = line.substr(0, line.find("|") - 1); // trim
    date.erase(date.find_last_not_of(" \n\r\t") + 1);
    value_str = line.substr(line.find("|") + 1, line.size() - line.find("|"));
    value_str.erase(value_str.find_last_not_of(" \n\r\t") + 1);
    value     = std::strtod(value_str.c_str(), NULL);
    if (line.find("|") == std::string::npos) 
      std::cout << "Error: bad input => " << line << std::endl;
    else if (value < 0) 
      std::cout << "Error: not a positive number.\n";
    else if (value > 10000) 
      std::cout << "Error: too large a number.\n";
    else if (this->find(date) != this->end())
      std::cout << date << " => " << value << " = " << (value * (this->find(date)->second) / 100.) << std::endl;
    else {
      std::map<std::string, unsigned long long>::iterator upper = this->upper_bound(date);
      std::map<std::string, unsigned long long>::iterator lower = --upper;
      std::cout << date << " => " << value << " = " << (value * (lower->second) / 100.) << std::endl;

      //std::cout << date << " => " << value << " * " << (this->lower_bound(date)->second / 100.) << " = " << (value * this->lower_bound(date)->second / 100.) << std::endl; // if no date
    //std::cout << date << " => " << value << " * " << this->find(date)->second / 100. << std::endl; // if no date
    }
  }
	in.close();
}