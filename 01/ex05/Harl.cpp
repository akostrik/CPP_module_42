#include "Harl.hpp"

Harl::Harl() {
};

void Harl::debug(void) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n";
};

void Harl::info(void) {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
};

void Harl::warning(void) {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
};

void Harl::error(void) {
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
};

void Harl::complain(std::string level) {
  void        (Harl::*functionPtr[4])();
  std::string messages[] = {"debug", "info", "warning", "error" };

  functionPtr[0] = &Harl::debug;
  functionPtr[1] = &Harl::info;
  functionPtr[2] = &Harl::warning;
  functionPtr[3] = &Harl::error;

  for (int i = 0; i < 4; i++)
    if (messages[i] == level)
      (this->*functionPtr[i])();

  // 2nd version (but maps are prohbited by the subject)
  // std::map<std::string, void(*)()> m;
  // m["debug"]   = debug;
  // m["info"]    = info;
  // m["warning"] = warning;
  // m["error"]   = error;
  // m[level]();
};
