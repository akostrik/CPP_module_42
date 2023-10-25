#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <cctype>
#include <string>
#include <iostream>
#include <cstring>

class Weapon
{
private:
	std::string type;

public:
	std::string	getType();
	void 		setType(std::string type);
};

#endif