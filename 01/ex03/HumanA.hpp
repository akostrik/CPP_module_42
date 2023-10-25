#ifndef HUMANA_HPP
# define NUMANA_HPP

#include <cctype>
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>

#include "Weapon.hpp"

class HumanA
{
private:
	std::string	name;
	Weapon		weapon;

public:
	HumanA(std::string, Weapon);
	void attack();
};

#endif