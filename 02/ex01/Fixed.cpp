#include "Fixed.hpp"

Fixed::Fixed() {
  std::cout << "Default constructor called" << std::endl;
  this->fpv = 0;
}

// a new object is created as a copy of the existing object
Fixed::Fixed(const Fixed &obj) {
  std::cout << "Copy constructor called" << std::endl;
  // this->setRawBits(obj.getRawBits()); ?
	*this = obj;
}

// an already initialized object is assigned to a new value from another existing object
Fixed& Fixed::operator = (Fixed const &obj) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &obj)
    this->fpv = obj.getRawBits();
  return (*this);
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
};

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return this->fpv;
}

void Fixed::setRawBits(const int _fpv) {
	this->fpv = _fpv;
}
