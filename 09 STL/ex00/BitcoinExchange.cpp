#include "BitcoinExchange.hpp"

/////////////////////////////////////////////////////////////////////////////////// UTILS
void trimR(std::string& s) {
  std::string::size_type pos = s.find_last_not_of(" \f\n\r\t\v");
  s.erase(pos + 1);
}

void trimL( std::string& s) {
  std::string::size_type pos = s.find_first_not_of(" \f\n\r\t\v");
  s.erase(0, pos);
}

void trim(std::string& s) {
  trimR(s);
  trimL(s);
}

void print_without_trailing_zeros(std::string date, unsigned long long n) {
  if (n % 100 == 0)
    std::cout << date << " => " << n << " = " << n / 100 << std::endl;
  else if (n % 10 == 0)
    std::cout << date << " => " << n << " = " << n / 100 << "." << (n / 10) << std::endl;
  else
    std::cout << date << " => " << n << " = " << n / 100 << "." << n % 100 << std::endl;
}

bool is_valid_date(std::string date) {
  regex_t regex;
  bool ok;

  regcomp(&regex, "[2-9][0-9][0-9][0-9][-]0[13578][-][0-2][0-9]", 0); // compile regex // janv march may july aug
  ok = !regexec(&regex, date.c_str(), 0, NULL, 0); // execute
  regfree(&regex);
  if (ok)
    return true;
  regcomp(&regex, "[2-9][0-9][0-9][0-9][-]0[13578][-][3][0-1]", 0);
  ok = !regexec(&regex, date.c_str(), 0, NULL, 0);
  regfree(&regex);
  if (ok)
    return true;

  regcomp(&regex, "[2-9][0-9][0-9][0-9][-]1[02][-][0-2][0-9]", 0); // octob decem
  ok = !regexec(&regex, date.c_str(), 0, NULL, 0);
  regfree(&regex);
  if (ok)
    return true;
  regcomp(&regex, "[2-9][0-9][0-9][0-9][-]1[02][-][3][0-1]", 0);
  ok = !regexec(&regex, date.c_str(), 0, NULL, 0);
  regfree(&regex);
  if (ok)
    return true;

  regcomp(&regex, "[2-9][0-9][0-9][0-9][-]0[469][-][0-2][0-9]", 0); // april june sept
  ok = !regexec(&regex, date.c_str(), 0, NULL, 0);
  regfree(&regex);
  if (ok)
    return true;
  regcomp(&regex, "[2-9][0-9][0-9][0-9][-]0[469][-][3][0]", 0);
  ok = !regexec(&regex, date.c_str(), 0, NULL, 0);
  regfree(&regex);
  if (ok)
    return true;

  regcomp(&regex, "[2-9][0-9][0-9][0-9][-]11[-][0-2][0-9]", 0); // nov
  ok = !regexec(&regex, date.c_str(), 0, NULL, 0);
  regfree(&regex);
  if (ok)
    return true;
  regcomp(&regex, "[2-9][0-9][0-9][0-9][-]11[-][3][0]", 0);
  ok = !regexec(&regex, date.c_str(), 0, NULL, 0);
  regfree(&regex);
  if (ok)
    return true;

  regcomp(&regex, "[2-9][0-9][0-9][0-9][-]02[-][01][0-9]", 0); // feb
  ok = !regexec(&regex, date.c_str(), 0, NULL, 0);
  regfree(&regex);
  if (ok)
    return true;
  regcomp(&regex, "[2-9][0-9][0-9][0-9][-]02[-][2][0-8]", 0);
  ok = !regexec(&regex, date.c_str(), 0, NULL, 0);
  regfree(&regex);
  if (ok)
    return true;

  std::string year_str = date.substr(0, date.find("-")); // feb 29
  int year = std::strtol(year_str.c_str(), NULL, 10);
  if (year % 4 == 0 && year % 400 != 0) {
    regcomp(&regex, "[2-9][0-9][0-9][0-9][-]02[-]29", 0);
    ok = !regexec(&regex, date.c_str(), 0, NULL, 0);
    regfree(&regex);
    if (ok)
      return true;
  }

  return false;
}

// modify "input.csv" !!!!!!!!!!!!! empty line!

///////////////////////////////////////////////////////////////////////////////////
BitcoinExchange::BitcoinExchange() : std::map<std::string, unsigned long long>() {
	std::ifstream      in(DB_FILE);
	std::string        line;
  std::string        date;
  std::string        dollars;
  std::string        cents;
  unsigned long long day_price_in_cents;

	if (!in.is_open())
		throw std::runtime_error("database file problem");
  std::getline(in, line); // skip first line
 	while (getline (in, line)) {
    date    = line.substr(0, line.find(","));
    trim(date);
    if (!is_valid_date(date))
      std::cout << "Error: the date " << date << " is invalid (in the database).\n";
    dollars = line.substr(11, line.find(".") - line.find(",") - 1);
    trim(dollars);
    cents   = line.substr(line.find(".") + 1, line.size() - line.find("."));
    trim(cents);
    day_price_in_cents = 100 * std::strtol(dollars.c_str(), NULL, 10);
    if (line.find(".") != std::string::npos && cents.size() == 2)
      day_price_in_cents += std::strtol(cents.c_str(), NULL, 10);
    else if (line.find(".") != std::string::npos && cents.size() == 1)
      day_price_in_cents += 10 * std::strtol(cents.c_str(), NULL, 10);
    this->insert(std::pair<std::string, unsigned long long>(date, day_price_in_cents));
  }
	in.close();
  if (this->size() == 0)
    throw std::underflow_error("Error: database file es empty");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& o) : std::map<std::string, unsigned long long>() {
  *this = o;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& o) {
  for(BitcoinExchange::const_iterator it = o.begin(); it != o.end(); it++)
    this->insert(std::pair<std::string, unsigned long long>(it->first, it->second));
  return *this;
}


///////////////////////////////////////////////////////////////////////////////////

void BitcoinExchange::run(std::string filename) {
	std::ifstream      in(filename.c_str());
	std::string        line;
  std::string        date;
  std::string        value_str;
  double             value;
  unsigned long long day_price_in_cents;
  bool               file_is_empty = true;

  if (!in.is_open())
    throw std::runtime_error("argument file problem");
  std::getline(in, line);
 	while (getline (in, line)) {
    date      = line.substr(0, line.find("|") - 1);
    trim(date);
    value_str = line.substr(line.find("|") + 1, line.size() - line.find("|"));
    trim(value_str);
    value     = std::strtod(value_str.c_str(), NULL);
    if (line.find("|") == std::string::npos) 
      std::cout << "Error: bad input => " << line << std::endl;
    else if (value < 0) 
      std::cout << "Error: " << value << " is not a positive number.\n";
    else if (value > 10000) 
      std::cout << "Error: " << value << " is a too large number.\n";
    else if(this->find(date) == this->end() && this->upper_bound(date) == this->begin())
      std::cout << "Error: the date " << date << " is invalid (the earliest possible date is 2009-01-02).\n";
    else if (!is_valid_date(date))
      std::cout << "Error: the date " << date << " is invalid.\n";
    else {
      if (this->find(date) != this->end())
        day_price_in_cents = this->find(date)->second;
      else
        day_price_in_cents = (--(this->upper_bound(date)))->second;
      print_without_trailing_zeros(date, (unsigned long long)value * day_price_in_cents);
    }
    file_is_empty = false;
  }
	in.close();
  if (file_is_empty)
    throw std::underflow_error("Error: argument file es empty");
}
