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
  *this = obj; // ?
};

// an already initialized object is assigned to a new value from another existing object
// copy assignment operator overload
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

ClapTrap&   operator = (const ClapTrap &obj) {

}

void ClapTrap::attack(const std::string& target) {

};

void ClapTrap::takeDamage(unsigned int amount) {

};

void ClapTrap::beRepaired(unsigned int amount) {

};

// ClapTrap <name> attacks <target>, causing <damage> points of damage!