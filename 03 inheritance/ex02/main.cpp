#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void ) {
  std::cout << "default constructor tests:" << std::endl;
  ClapTrap clap1;                   // 1 constructor
  ClapTrap clap2 = ClapTrap();      // 1 constructor
  ScavTrap scav1;                   // 2 constructors
  FragTrap frag1;                   // 2 constructors

  std::cout << std::endl << "string constructor tests:" << std::endl;
  ClapTrap clap3 = ClapTrap("Clap"); // 1 constructor
  ClapTrap scav2 = ScavTrap("Scav"); // 3 constructors and 2 destructors
  ScavTrap scav3 = ScavTrap("Scav"); // 2 constructors
  ClapTrap frag2 = ScavTrap("Frag"); // 3 constructors and 2 destructors
  FragTrap frag3 = FragTrap("Frag"); // 2 constructors

  std::cout << std::endl << "copy constructor tests:" << std::endl;
  ClapTrap clap4 = ClapTrap(clap1);  // 1 constructor
  ScavTrap scav4 = ScavTrap(scav1);  // 2 constructors
  FragTrap frag4 = FragTrap(frag1);  // 2 constructors

  std::cout << std::endl << "functions inherited by ClapTrap and FrapTrap from ClapTrap (takeDamage, beRepaired):" << std::endl;
  clap1.takeDamage(2);
  scav1.takeDamage(2);
  frag1.takeDamage(2);
  clap1.beRepaired(2);
  scav1.beRepaired(2);
  frag1.beRepaired(2);

  std::cout << std::endl << "functions implemented diffenently in ClapTrap, ScavTrap and FragTrap (attack):" << std::endl;
  clap1.attack("Mouse");
  scav1.attack("Mouse");
  frag1.attack("Mouse");

  std::cout << std::endl << "functions implemented in ScavTrap only (guardGate):" << std::endl;
  scav1.guardGate();

  std::cout << std::endl << "functions implemented in FragTrap only (highFivesGuys):" << std::endl;
  frag1.highFivesGuys();

  std::cout << std::endl << "return:" << std::endl;
  return 0;                          // 18 destructors
}