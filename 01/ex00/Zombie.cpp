#include "Zombie.hpp"

Zombie::Zombie(std::string name_p)
{
	this->name = name_p;
};

void Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
};
