#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
  std::cout << "Anonymus ScavTrap default constructor called" << std::endl;
	ScavTrap("");
};

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
  std::cout << name << " ScavTrap string constructor called" << std::endl;
  this->_hitPoints    = 100;
  this->_energyPoints = 50;
  this->_attackDamage = 20;
};

// вызываем конструктор копирования базового класса
ScavTrap::ScavTrap(const ScavTrap &obj) : ClapTrap(obj){
  std::cout << obj._name << " ScavTrap copy constructor called" << std::endl;
  *this = obj;
};

ScavTrap::~ScavTrap() {
  std::cout << this->_name << " ScavTrap destructor called" << std::endl;
};

void ScavTrap::attack(const std::string& target) {
  if (this->_energyPoints <= 0)
  {
    std::cout << "ScavTrap " << this->_name << " is out of energy!" << std::endl;
    return;
  }
  std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage" << std::endl;
  this->_energyPoints --;
};

void ScavTrap::guardGate() {
  std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode" << std::endl;
};
