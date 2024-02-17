#include "BitcoinExchange.hpp"

/////////////////////////////////////////////////////////////////////////////////// UTILS
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

  regcomp(&regex, "[0-9][0-9][0-9][0-9][-](01|03|05|07|08|10|12)[-]([0-2][0-9]|30|31)", REG_EXTENDED); // 31
  ok = !regexec(&regex, date.c_str(), 0, NULL, 0);
  regfree(&regex);
  if (ok)
    return true;

  regcomp(&regex, "[0-9][0-9][0-9][0-9][-](04|06|09|11)[-]([0-2][0-9]|30)", REG_EXTENDED); // 30
  ok = !regexec(&regex, date.c_str(), 0, NULL, 0);
  regfree(&regex);
  if (ok)
    return true;

  regcomp(&regex, "[0-9][0-9][0-9][0-9][-]02[-]([01][0-9]|2[0-8])", REG_EXTENDED); // 28
  ok = !regexec(&regex, date.c_str(), 0, NULL, 0);
  regfree(&regex);
  if (ok)
    return true;

  regcomp(&regex, "[0-9][0-9][0-9][0-9][-]02[-]29", REG_EXTENDED); // 29
  ok = !regexec(&regex, date.c_str(), 0, NULL, 0);
  regfree(&regex);
  int year = std::strtol(date.substr(0, date.find("-")).c_str(), NULL, 10);
  if (ok && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
    return true;

  return false;
}

bool is_valid_db_line(std::string line) {
  regex_t     regex;
  bool        ok;
  std::string date = line.substr(0, line.find(","));

  regcomp(&regex, "[0-9][0-9][0-9][0-9][-][0-9][0-9][-][0-9][0-9][,]([0-9]+[.]?[0-9]{0,2}|[0-9]*[.][0-9][0-9]?)$", REG_EXTENDED);
  ok = !regexec(&regex, line.c_str(), 0, NULL, 0);
  regfree(&regex);
  if (!ok) {
    std::cout << "Error: " << line << " : invalid line in the database\n";
    return false;
  }
  if (!is_valid_date(date)) {
    std::cout << "Error: invalide date " << date << " is the database.\n";
    return false;
  }
  return true;
}

bool is_valid_arg_file_line(std::string line, double value, std::string firstDate) {
  regex_t     regex;
  bool        ok;
  std::string date = line.substr(0, line.find("|"));

  regcomp(&regex, "[0-9][0-9][0-9][0-9][-][0-9][0-9][-][0-9][0-9][|][-]?([0-9]+[.]?[0-9]*|[0-9]*[.][0-9][0-9]?)$", REG_EXTENDED);
  ok = !regexec(&regex, line.c_str(), 0, NULL, 0);
  regfree(&regex);

  if (!ok)
    return (std::cout << "Error: " << line << " : invalid line in the argument file.\n", false);
  if (std::count(line.begin(), line.end(), '-') == 3)
    return (std::cout << "Error: not a positive number.\n", false);
  if (value > 10000)
    return (std::cout << "Error: " << value << " is a too large number.\n", false);
  if(date < firstDate)
    return (std::cout << "Error: the date " << date << " is invalid (the earliest possible date is " << firstDate << ").\n", false);
  if (!is_valid_date(date))
    return (std::cout << "Error: invalide date " << date << " in the argument file.\n", false);
  return true;
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
  bool               file_is_empty = true;

  if (!in.is_open())
    throw std::runtime_error("database file problem");
  std::getline(in, line); // skip first line
  while (getline (in, line)) {
    file_is_empty = false;
    line.erase(std::remove_if(line.begin(),line.end(),isspace),line.end()); // remove spaces
    if (!is_valid_db_line(line))
      continue ;
    date    = line.substr(0, line.find(","));
    dollars = line.substr(11, line.find(".") - line.find(",") - 1);
    cents   = line.substr(line.find(".") + 1, line.size() - line.find("."));
    day_price_in_cents = 100 * std::strtol(dollars.c_str(), NULL, 10);
    if (line.find(".") != std::string::npos && cents.size() == 2)
      day_price_in_cents += std::strtol(cents.c_str(), NULL, 10);
    else if (line.find(".") != std::string::npos && cents.size() == 1)
      day_price_in_cents += 10 * std::strtol(cents.c_str(), NULL, 10);
    this->insert(std::pair<std::string, unsigned long long>(date, day_price_in_cents));
  }
  in.close();
  if (file_is_empty)
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
  double             value;
  unsigned long long day_price_in_cents;
  bool               file_is_empty = true;

  if (!in.is_open())
    throw std::runtime_error("argument file problem");
  std::getline(in, line);
  while (getline (in, line)) {
    file_is_empty = false;
    line.erase(std::remove_if(line.begin(),line.end(),isspace),line.end());
    date = line.substr(0, line.find("|"));
    value = std::strtod(line.substr(line.find("|") + 1, line.size() - line.find("|")).c_str(), NULL);
    if (!is_valid_arg_file_line(line, value, this->begin()->first))
      continue ;
    if (this->find(date) != this->end())
      day_price_in_cents = this->find(date)->second;
    else
      day_price_in_cents = (--(this->upper_bound(date)))->second;
    print_without_trailing_zeros(date, (unsigned long long)value * day_price_in_cents);
  }
  in.close();
  if (file_is_empty)
    throw std::underflow_error("Error: argument file es empty");
}