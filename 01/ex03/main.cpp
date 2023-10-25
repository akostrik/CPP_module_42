#include <cctype>
#include <string>
#include <iostream>
#include <cstring>

#include "Weapon.hpp"
#include "HumanA.hpp"

int	main()
{
	Weapon w1;
	w1.setType("rifle");
	HumanA *h1 = new HumanA("Yanki", w1);
	h1->attack();

	// Weapon w2;
	// w2.setType("Kalashnikov");
	// HumanA *h2 = new HumanA(w2);


	return (0);
}