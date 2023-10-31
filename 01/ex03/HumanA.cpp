#include "HumanA.hpp"

HumanA::HumanA(std::string name_, Weapon& weaponREF_) : weaponREF(weaponREF_) {
	if (name_ == "")
		this->name = "anonymous";
	else
		this->name = name_;
}






void HumanA::attack(void) {
	if (this->weaponREF.getType() != "")
		std::cout << this->name << " attacks with theirs " << this->weaponREF.getType() << std::endl;
	else
		std::cout << this->name << " attacks without weapon" << std::endl;
};
