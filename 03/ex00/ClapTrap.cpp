#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
  std::cout << "Default constructor called" << std::endl;
  this->raw = 0;
}

ClapTrap::ClapTrap() {
  std::cout << "Int constructor called" << std::endl;
  this->raw = 0;
}

// a new object is created as a copy of the existing object
ClapTrap::ClapTrap(const ClapTrap &obj) {
  *this = obj; // ?
}

// an already initialized object is assigned to a new value from another existing object
// copy assignment operator overload
ClapTrap& ClapTrap::operator = (ClapTrap const &obj) {
  if (this != &obj)
    this->raw = obj.getRawBits();
  return (*this);
}

ClapTrap::~ClapTrap() {
};
