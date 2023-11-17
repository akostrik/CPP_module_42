#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void ) {
  std::cout << "initialisation Cat:" << std::endl;
  ClapTrap cat("Cat");

  std::cout << std::endl << "initialisation Cat Robot:" << std::endl;
  ScavTrap cat_robot;

  std::cout << std::endl << "copy:" << std::endl;
  cat_robot = ScavTrap("Cat Robot");

  std::cout << std::endl << "functions inherited by Cat Robot (takeDamage, beRepaired):" << std::endl;
  cat.takeDamage(2);
  cat.beRepaired(2);
  cat_robot.takeDamage(2);
  cat_robot.beRepaired(2);

  std::cout << std::endl << "functions implemented in both Cat and Cat Robot (attack):" << std::endl; // ?
  cat.attack("Mouse");
  cat_robot.attack("Mouse Robot");

  std::cout << std::endl << "functions implemented in Cat Robot (guardGate):" << std::endl; // ?
  cat_robot.guardGate();

  std::cout << std::endl << "return:" << std::endl;
  return 0;
}