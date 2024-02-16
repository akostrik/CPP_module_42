#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : std::map<std::string, unsigned long long>() {
// modify "input.csv"
	std::ifstream      in(DB_FILE);
	std::string        line;
  std::string        date;
  std::string        dollars;
  std::string        cents;
  unsigned long long day_price_in_cents;

	if (!in.is_open())
		throw std::exception(); // !
  std::getline(in, line); // skip first line
 	while (getline (in, line)) {
    date    = line.substr(0, line.find(","));
    date.erase(date.find_last_not_of(" \n\r\t") + 1);
    dollars = line.substr(11, line.find(".") - line.find(",") - 1);
    dollars.erase(dollars.find_last_not_of(" \n\r\t") + 1);
    cents   = line.substr(line.find(".") + 1, line.size() - line.find("."));
    cents.erase(cents.find_last_not_of(" \n\r\t")+1);
    day_price_in_cents   = 100 * std::strtol(dollars.c_str(), NULL, 10);
    if (line.find(".") != std::string::npos && cents.size() == 2)
      day_price_in_cents += std::strtol(cents.c_str(), NULL, 10);
    else if (line.find(".") != std::string::npos && cents.size() == 1)
      day_price_in_cents += 10 * std::strtol(cents.c_str(), NULL, 10);
    this->insert(std::pair<std::string, unsigned long long>(date, day_price_in_cents));
  }
	in.close();
  if (this->size() == 0)
		throw std::exception(); // file es empty
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

// std::string BitcoinExchange::convert(double v) {
//   std::stringstream ss;                                         // Print v to a string
//   ss << std::fixed << std::setprecision(2) << v;
//   std::string str = ss.str();
//   // Ensure that there is a decimal point somewhere (there should be)
//   if(str.find('.') != std::string::npos) {
//     // Remove trailing zeroes
//     str = str.substr(0, str.find_last_not_of('0')+1);
//     // If the decimal point is now the last character, remove that as well
//     if(str.find('.') == str.size()-1)
//         str = str.substr(0, str.size()-1);
//   }
//   return str;
// }

bool BitcoinExchange::is_valid_date(std::string date) {
  regex_t regex;

  regcomp(&regex, "[2-9][0-9][0-9][0-9][-]0[13578][-][0-2][0-9]", 0); // compile reg expression // janv march may july aug
  if (!regexec(&regex, date.c_str(), 0, NULL, 0))                     // execute
    return true;
  regcomp(&regex, "[2-9][0-9][0-9][0-9][-]0[13578][-][3][0-1]", 0);
  if (!regexec(&regex, date.c_str(), 0, NULL, 0))
    return true;

  regcomp(&regex, "[2-9][0-9][0-9][0-9][-]1[02][-][0-2][0-9]", 0); // octob decem
  if (!regexec(&regex, date.c_str(), 0, NULL, 0))
    return true;
  regcomp(&regex, "[2-9][0-9][0-9][0-9][-]1[02][-][3][0-1]", 0);
  if (!regexec(&regex, date.c_str(), 0, NULL, 0))
    return true;

  regcomp(&regex, "[2-9][0-9][0-9][0-9][-]0[469][-][0-2][0-9]", 0); // april june sept
  if (!regexec(&regex, date.c_str(), 0, NULL, 0))
    return true;
  regcomp(&regex, "[2-9][0-9][0-9][0-9][-]0[469][-][3][0]", 0);
  if (!regexec(&regex, date.c_str(), 0, NULL, 0))
    return true;

  regcomp(&regex, "[2-9][0-9][0-9][0-9][-]11[-][0-2][0-9]", 0); // nov
  if (!regexec(&regex, date.c_str(), 0, NULL, 0))
    return true;
  regcomp(&regex, "[2-9][0-9][0-9][0-9][-]11[-][3][0]", 0);
  if (!regexec(&regex, date.c_str(), 0, NULL, 0))
    return true;

  regcomp(&regex, "[2-9][0-9][0-9][0-9][-]02[-][01][0-9]", 0); // feb
  if (!regexec(&regex, date.c_str(), 0, NULL, 0))
    return true;
  regcomp(&regex, "[2-9][0-9][0-9][0-9][-]02[-][2][0-8]", 0);
  if (!regexec(&regex, date.c_str(), 0, NULL, 0))
    return true;

  std::string year_str = date.substr(0, date.find("-")); // feb 29
  int year = std::strtol(year_str.c_str(), NULL, 10);
  if (year % 4 == 0 && year % 400 != 0) {
    regcomp(&regex, "[2-9][0-9][0-9][0-9][-]02[-]29", 0);
    if (!regexec(&regex, date.c_str(), 0, NULL, 0))
      return true;
  }

  return false;
}

void BitcoinExchange::print_without_trailing_zeros(std::string date, unsigned long long n) {
  if (n % 100 == 0)
    std::cout << date << " => " << n << " = " << n / 100 << std::endl;
  if (n % 10 == 0)
    std::cout << date << " => " << n << " = " << n / 100 << "." << (n / 10) << std::endl;
  else
    std::cout << date << " => " << n << " = " << n / 100 << "." << n % 100 << std::endl;
}

void BitcoinExchange::run(std::string filename) {
	std::ifstream in(filename.c_str());
	std::string        line;
  std::string        date;
  std::string        value_str;
  double             value;
  unsigned long long day_price_in_cents;

	if (!in.is_open())
		throw std::exception(); // !
  std::getline(in, line);
 	while (getline (in, line)) {
    date      = line.substr(0, line.find("|") - 1);
    date.erase(date.find_last_not_of(" \n\r\t") + 1);
    value_str = line.substr(line.find("|") + 1, line.size() - line.find("|"));
    value_str.erase(value_str.find_last_not_of(" \n\r\t") + 1);
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
  }
	in.close();
}
