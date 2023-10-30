#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
	this->_weapon = NULL; //
};

void HumanB::attack(void) const
{
	if (this->_weapon != NULL && this->_weapon->getType() != "")
		std::cout << this->_name << " attacks with theirs " << this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " attacks without weapon" << std::endl;
};

void HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon; // &
};
