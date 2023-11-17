#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
  std::cout << "ClapTrap              default constructor" << std::endl;
  this->_name = "anonymous";
  this->_hitPoints    = 10;
  this->_energyPoints = 10;
  this->_attackDamage = 0;
};

ClapTrap::ClapTrap(std::string name) {
  std::cout << "ClapTrap " << std::setw(12) << std::left << this->_name << " string constructor" << std::endl;
  if(name == "")
    this->_name = "anonymous";
  else
    this->_name = name;
  this->_hitPoints    = 10;
  this->_energyPoints = 10;
  this->_attackDamage = 0;
};

ClapTrap::ClapTrap(const ClapTrap &obj) {
  std::cout << "ClapTrap " << std::setw(12) << std::left << this->_name << " copy constructor" << std::endl;
  *this = obj;
};

ClapTrap& ClapTrap::operator = (ClapTrap const &obj) {
  std::cout << "ClapTrap " << std::setw(12) << std::left << obj._name << " copy assignment operator" << std::endl;
  if (this != &obj) {
    this->_name         = obj._name;
    this->_hitPoints    = obj._hitPoints;
    this->_energyPoints = obj._energyPoints;
    this->_attackDamage = obj._attackDamage;
  }
  return (*this);
};

ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap " << std::setw(12) << std::left << this->_name << " destructor" << std::endl;
};

// member functions

void ClapTrap::attack(const std::string& target) {
  if (this->_hitPoints <= 0) //
  {
    std::cout << "ClapTrap " << std::setw(12) << std::left << this->_name << " can not attack, he is out of hitPoints" << std::endl;
    return;
  }
  if (this->_energyPoints <= 0)
  {
    std::cout << "ClapTrap " << std::setw(12) << std::left << this->_name << " is out of energy" << std::endl;
    return;
  }
  std::cout << "ClapTrap " << std::setw(12) << std::left<< this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage" << std::endl;
  this->_energyPoints --;
};

void ClapTrap::takeDamage(unsigned int amount) {
  if (this->_hitPoints <= 0) //
  {
    std::cout << "ClapTrap " << std::setw(12) << std::left << this->_name << " can not take damage, he is out of hitPoints" << std::endl;
    return;
  }
  std::cout << "ClapTrap " << std::setw(12) << std::left<< this->_name << " takes " << amount << " damage!" << std::endl;
  if (this->_hitPoints <= amount)
    std::cout << "ClapTrap " << std::setw(12) << std::left << this->_name << " is out of hitPoints, he leaves the game" << std::endl; //
  this->_hitPoints -= amount;
};

void ClapTrap::beRepaired(unsigned int amount) {
  if (this->_hitPoints <= 0)
  {
    std::cout << "ClapTrap " << std::setw(12) << std::left << this->_name << " can not be repaired, he is out of hitPoints" << std::endl;
    return;
  }
  if (this->_energyPoints <= amount)
  {
    std::cout << "ClapTrap " << std::setw(12) << std::left<< this->_name << " is out of energy" << std::endl;
    return;
  }
  std::cout << "ClapTrap " << std::setw(12) << std::left<< this->_name << " repairs itself for " << amount << " hit points!" << std::endl;
  this->_energyPoints -= 1;
  this->_hitPoints += amount;
};
