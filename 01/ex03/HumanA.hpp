#ifndef HUMANA_HPP
# define NUMANA_HPP

# include "Weapon.hpp"

class HumanA {

private:
	std::string name;
	Weapon&     weaponREF; //

public:
	            HumanA(std::string name_, Weapon& weaponREF_); //
	void        attack(void);
};

#endif

// weaponREF.getType()