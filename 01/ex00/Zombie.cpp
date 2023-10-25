#include "Zombie.hpp"

Zombie::Zombie()
{
};

Zombie::Zombie(std::string name_p)
{
	this->name = name_p;
};

Zombie::~Zombie()
{
	std::cout << std::setw(27) << std::left << this->name << " is destructed" << std::endl;
};

void Zombie::announce(void)
{
	std::cout << std::setw(26) << std::left << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
};
