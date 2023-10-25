#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <cctype>
#include <string>
#include <iostream>
#include <cstring>

class Zombie
{
private:
	std::string name;

public:
	Zombie();
	void announce(void);
};

#endif