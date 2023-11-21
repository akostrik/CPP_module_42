#include "HumanB.hpp"

HumanB::HumanB(std::string name_) {
	if (name_ == "")
		this->name = "anonymous";
	else
		this->name = name_;
	this->weaponPTR = NULL;
};

void HumanB::setWeapon(Weapon& weaponPTR_) {
	this->weaponPTR = &weaponPTR_;
};

void HumanB::attack(void) {
	if (this->weaponPTR != NULL && this->weaponPTR->getType() != "")
		std::cout << this->name << " attacks with theirs " << this->weaponPTR->getType() << std::endl;
	else
		std::cout << this->name << " attacks without weapon" << std::endl;
};
