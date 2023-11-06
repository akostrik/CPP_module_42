#include "Harl.hpp"

Harl::Harl() {
};

void debug(void) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n";
};

void info(void) {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
};

void warning(void) {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
};

void error(void) {
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
};

void Harl::complain(std::string level) {
  std::map<std::string, void(*)()> m;
  m["debug"]   = debug;
  m["info"]    = info;
  m["warning"] = warning;
  m["error"]   = error;
  m[level]();
};
