#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
  ClapTrap("");
};

ClapTrap::ClapTrap(std::string name) {
  if(name == "")
    this->_name = "anonymus";
  else
    this->_name = name;
  std::cout << this->_name << " ClapTrap string constructor called" << std::endl;
  this->_hitPoints    = 10;
  this->_energyPoints = 10;
  this->_attackDamage = 0;
};

ClapTrap::ClapTrap(const ClapTrap &obj) {
  std::cout << obj._name << " ClapTrap copy constructor called" << std::endl;
  *this = obj;
};

ClapTrap& ClapTrap::operator = (ClapTrap const &obj) {
  if (this != &obj) {
    std::cout << obj._name << "Copy assignment operator called" << std::endl;
    this->_name         = obj._name;
    this->_hitPoints    = obj._hitPoints;
    this->_energyPoints = obj._energyPoints;
    this->_attackDamage = obj._attackDamage;
  }
  return (*this);
};

ClapTrap::~ClapTrap() {
  std::cout << this->_name << " ClapTrap destructor called" << std::endl;
};

void ClapTrap::attack(const std::string& target) {
  if (this->_energyPoints <= 0)
  {
    std::cout << "ClapTrap " << this->_name << " is out of energy!" << std::endl;
    return;
  }
  std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage" << std::endl;
  this->_energyPoints --;
};

void ClapTrap::takeDamage(unsigned int amount) {
  if (this->_hitPoints <= amount)
  {
    std::cout << "ClapTrap " << this->_name << " is dead!" << std::endl;
    return;
  }
  std::cout << "ClapTrap " << this->_name << " takes " << amount << " damage!" << std::endl;
  this->_hitPoints -= amount;
};

void ClapTrap::beRepaired(unsigned int amount) {
  if (this->_energyPoints <= amount)
  {
    std::cout << "ClapTrap " << this->_name << " is out of energy!" << std::endl;
    return;
  }
  std::cout << "ClapTrap " << this->_name << " repairs itself for " << amount << " hit points!" << std::endl;
  this->_energyPoints -= 1;
  this->_hitPoints += amount;
};
