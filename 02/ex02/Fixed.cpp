#include "Fixed.hpp"

Fixed::Fixed() {
  std::cout << "Default constructor called" << std::endl;
  this->raw = 0;
}

Fixed::Fixed(const int raw_) {
  std::cout << "Int constructor called" << std::endl;
  this->raw = raw_ * 256;
}

Fixed::Fixed(const float raw_) {
  std::cout << "Float constructor called"       << std::endl;
  int raw_int = (int)(raw_);
  int raw_dec = roundf((raw_ - (int)raw_)*256);
  this->raw = raw_int * 256 + raw_dec;
}

// a new object is created as a copy of the existing object
Fixed::Fixed(const Fixed &obj) {
  std::cout << "Copy constructor called" << std::endl;
  *this = obj; // ?
}

// an already initialized object is assigned to a new value from another existing object
// copy assignment operator overload
Fixed& Fixed::operator = (Fixed const &obj) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &obj)
    this->raw = obj.getRawBits();
  return (*this);
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
};

int Fixed::getRawBits(void) const {
  return this->raw;
}

void Fixed::setRawBits(const int _raw) {
	this->raw = _raw;
}

float Fixed::toFloat(void) const {
  return roundf(this->raw / 256) + ((this->raw % 256)) / 256.0;
}

int Fixed::toInt(void) const {
  return roundf(this->raw / 256);
}

// overload of the insertion operator <<
std::ostream& operator<<(std::ostream& os, Fixed const &f)
{
  os << f.toFloat();
  return os;
}

////////////////////////// NEW
bool Fixed::operator==(Fixed const &f1, Fixed const &f2) {
  std::cout << "Operator == called" << std::endl;
  return (f1.getRawBits() == f2.getRawBits());
}
