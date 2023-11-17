#include <iostream>
#include "ClapTrap.hpp"

int main( void ) {
  std::cout << "default constructor tests:" << std::endl;
  ClapTrap clap1;                   // 1 constructor
  ClapTrap clap2 = ClapTrap();      // 1 constructor

  std::cout << std::endl << "string constructor tests:" << std::endl;
  ClapTrap clap3 = ClapTrap("Clap"); // 1 constructor

  std::cout << std::endl << "copy constructor tests:" << std::endl;
  ClapTrap clap4 = ClapTrap(clap1);  // 1 constructor

  std::cout << std::endl << "functions (takeDamage, beRepaired, attack):" << std::endl;
  clap1.takeDamage(2);
  clap1.beRepaired(2);
  clap1.attack("Mouse");

  std::cout << std::endl << "return:" << std::endl;
  return 0;                          // 4 destructors
}