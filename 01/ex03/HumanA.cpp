#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon& weapon ) : _name(name), _weapon(weapon) {
}

// HumanA::HumanA(std::string _name, Weapon& _weapon)
// {
// 	this->name   = _name;
// 	this->weapon = _weapon;
// };

void HumanA::attack(void) const // 
{
	if (this->_weapon.getType() != "")
		std::cout << this->_name << " attacks with theirs " << this->_weapon.getType() << std::endl;
	else
		std::cout << this->_name << " attacks without weapon" << std::endl;
};
