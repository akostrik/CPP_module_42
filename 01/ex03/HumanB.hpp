#ifndef HUMANB_HPP
# define NUMANB_HPP

# include <cctype>
# include <iostream>
# include <string>
# include <cstring>
# include <iomanip>
# include "Weapon.hpp"

class HumanB
{
private:
	std::string	_name;
	Weapon*		_weapon; // *

public:
	HumanB(std::string name);
	void setWeapon(Weapon& weapon);
	void attack(void) const; // const ?
};

#endif
