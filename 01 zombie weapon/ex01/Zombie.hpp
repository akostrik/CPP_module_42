#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <cctype>
#include <string>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <list>
#include <cstddef>
#include <iostream>

class Zombie
{
private:
	std::string name;

public:
	Zombie();
	Zombie(std::string name_p);
	~Zombie();
	void announce(void);
	bool setName(std::string name);
};

#endif