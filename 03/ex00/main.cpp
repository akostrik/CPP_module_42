#include <iostream>
#include "ClapTrap.hpp"

int main( void ) {
  std::cout << "initialisation:" << std::endl;
  ClapTrap cat1("Cat1");
  ClapTrap cat2;

  std::cout << std::endl << "copy:" << std::endl;
  cat2 = ClapTrap("Cat2");

  std::cout << std::endl << "functions (takeDamage, beRepaired, attack):" << std::endl;
  cat1.takeDamage(2);
  cat1.beRepaired(2);
  cat1.attack("Mouse");

  std::cout << std::endl << "return:" << std::endl;
  return 0;
}