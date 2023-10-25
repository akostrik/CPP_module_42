#include "Zombie.hpp"

Zombie::Zombie()
{
};

Zombie::Zombie(std::string name)
{
	this->name = name;
};

Zombie::~Zombie()
{
	std::cout << std::setw(27) << std::left << this->name << " is destructed" << std::endl;
};

void Zombie::announce(void)
{
	std::cout << std::setw(26) << std::left << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
};

bool	Zombie::setName(std::string name)
{
	if (name == "")
		return (false);
	this->name = name;
	return (true);
}