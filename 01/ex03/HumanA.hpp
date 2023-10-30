#ifndef HUMANA_HPP
# define NUMANA_HPP

# include <cctype>
# include <iostream>
# include <string>
# include <cstring>
# include <iomanip>
# include "Weapon.hpp"

class HumanA
{
private:
	std::string	_name;
	Weapon&		_weapon;
  // Weapon&     _weapon;

public:
	HumanA(std::string name, Weapon& weapon);
	void attack(void) const; // const ?
};

#endif
