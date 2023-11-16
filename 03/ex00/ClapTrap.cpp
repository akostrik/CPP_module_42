#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
  std::cout << "Anonymus default constructor called" << std::endl;
  this->name = "anonymus";
  this->hitPoints    = 10;
  this->energyPoints = 10;
  this->attackDamage = 0;
};

ClapTrap::ClapTrap(std::string name_) {
  std::cout << name_ << " string constructor called" << std::endl;
  if(name_ == "")
    this->name = "anonymus";
  else
    this->name = name_;
  this->hitPoints    = 10;
  this->energyPoints = 10;
  this->attackDamage = 0;
};

// a new object is created as a copy of the existing object
ClapTrap::ClapTrap(const ClapTrap &obj) {
  std::cout << obj.name << " copy constructor called" << std::endl;
  *this = obj;
};

// an already initialized object is assigned to a new value from another existing object
ClapTrap& ClapTrap::operator = (ClapTrap const &obj) {
  if (this != &obj) {
    this->name         = obj.name;
    this->hitPoints    = obj.hitPoints;
    this->energyPoints = obj.energyPoints;
    this->attackDamage = obj.attackDamage;
  }
  return (*this);
};

ClapTrap::~ClapTrap() {
  std::cout << this->name << " destructor called" << std::endl;
};

void ClapTrap::attack(const std::string& target) {
  if (this->energyPoints <= 0)
  {
    std::cout << "ClapTrap " << this->name << " is out of energy!" << std::endl;
    return;
  }
  std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage" << std::endl;
  this->energyPoints --;
};

void ClapTrap::takeDamage(unsigned int amount) {
  if (this->hitPoints <= amount)
  {
    std::cout << "ClapTrap " << this->name << " is dead!" << std::endl;
    return;
  }
  std::cout << "ClapTrap " << this->name << " takes " << amount << " damage!" << std::endl;
  this->hitPoints -= amount;
};

void ClapTrap::beRepaired(unsigned int amount) {
  if (this->energyPoints <= amount)
  {
    std::cout << "ClapTrap " << this->name << " is out of energy!" << std::endl;
    return;
  }
  std::cout << "ClapTrap " << this->name << " repairs itself for " << amount << " hit points!" << std::endl;
  this->energyPoints --;
  this->hitPoints += amount;
};
