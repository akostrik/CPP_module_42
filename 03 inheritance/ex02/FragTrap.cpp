#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
  std::cout << "FragTrap              default constructor" << std::endl;
  this->_hitPoints    = 100;
  this->_energyPoints = 100;
  this->_attackDamage = 30;
};

FragTrap::FragTrap(std::string name) : ClapTrap(name){
  std::cout << "FragTrap " << std::setw(12) << std::left << this->_name << " string constructor" << std::endl;
  this->_hitPoints    = 100;
  this->_energyPoints = 100;
  this->_attackDamage = 30;
};

FragTrap::FragTrap(const FragTrap &obj) : ClapTrap(obj){
  std::cout << "FragTrap " << std::setw(12) << std::left << this->_name << " copy constructor" << std::endl;
  *this = obj; // lishnee ?
};

FragTrap::~FragTrap() {
  std::cout << "FragTrap " << std::setw(12) << std::left << this->_name << " destructor" << std::endl;
};

// member functions

void FragTrap::highFivesGuys() {
  if (this->_hitPoints <= 0)
  {
    std::cout << "FragTrap " << std::setw(12) << std::left << this->_name << " can not display a positive high fives request, he is out of hitPoints" << std::endl;
    return;
  }
  if (this->_energyPoints <= 0)
  {
    std::cout << "FragTrap " << std::setw(12) << std::left << this->_name << " can not display a positive high fives request, is out of energy" << std::endl;
    return;
  }
  std::cout << "FragTrap " << std::setw(12) << std::left << this->_name << " displays a positive high fives request" << std::endl;
};
