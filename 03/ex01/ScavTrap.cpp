#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
  std::cout << "ScavTrap anonymous    default constructor" << std::endl;
  ScavTrap("");
};

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
  std::cout << "ScavTrap " << std::setw(12) << std::left << this->_name << " string constructor" << std::endl;
  this->_hitPoints    = 100;
  this->_energyPoints = 50;
  this->_attackDamage = 20;
};

ScavTrap::ScavTrap(const ScavTrap &obj) : ClapTrap(obj){
  std::cout << "ScavTrap " << std::setw(12) << std::left << this->_name << " copy constructor" << std::endl;
  *this = obj;
};

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap " << std::setw(12) << std::left << this->_name << " destructor" << std::endl;
};

// member functions
void ScavTrap::attack(const std::string& target) {
  if (this->_energyPoints <= 0)
  {
    std::cout << "ScavTrap " << std::setw(12) << std::left << this->_name << " is out of energy!" << std::endl;
    return;
  }
  std::cout << "ScavTrap " << std::setw(12) << std::left << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage" << std::endl;
  this->_energyPoints --;
};

void ScavTrap::guardGate() {
  std::cout << "ScavTrap " << std::setw(12) << std::left << this->_name << " is now in Gate keeper mode" << std::endl;
};
