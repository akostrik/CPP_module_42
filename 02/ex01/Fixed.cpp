#include "Fixed.hpp"

///////////////////////////// utils
int nb_decimal_figures(float const _fpv)
{
  float fpv = _fpv;
  for (int i = 0; i < 8; i++)
	{
    if (roundf(fpv * 10) == roundf(fpv) * 10)
      return (i);
    fpv = 10 * fpv;
  }
	return (8);
}

int pow(int a, int n) {
  int res = 1;
  for(int i = 0; i < n; i++)
    res *= a;
  return (res);
}

/////////////////////////////
Fixed::Fixed() {
  std::cout << "Default constructor called" << std::endl;
  this->raw = 0;
}

// // NEW converts p to the corresponding fpv
// Fixed::Fixed(int const _raw) {
//   std::cout << "Int constructor called" << std::endl;
//   this->raw = _raw * 100000000;
// }

// // NEW converts p to the corresponding 
// // INT_MAX = 2 147 483 647
// Fixed::Fixed(float const _raw) {
//   std::cout << "Float constructor called" << std::endl;
//   this->raw = roundf(_raw * 100000000);
//   std::cout << "raw = " << _raw << " * 100 000 000 = " << this->raw << std::endl;
// }

Fixed::Fixed(const int _raw) {
  std::cout << "Int constructor called" << std::endl;
  this->raw = _raw << 8;
}

Fixed::Fixed(const float _raw) {
  std::cout << "Float constructor called"       << std::endl;
  std::cout << "  _raw            = : "         << _raw << std::endl;
  std::cout << "  1 << 8          = : "         << (1 << 8) << std::endl;
  std::cout << "  _raw * (1 << 8) = : "         << _raw * (1 << 8) << std::endl;
  std::cout << "  roundf(_raw * (1 << 8)) = : " << roundf(_raw * (1 << 8)) << std::endl;
	this->raw = roundf(_raw * (1 << 8));
}

// a new object is created as a copy of the existing object
Fixed::Fixed(const Fixed &obj) {
  std::cout << "Copy constructor called" << std::endl;
	*this = obj; // ?
}

// an already initialized object is assigned to a new value from another existing object
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

// NEW member function (Fixed::), converts the fixed-point value to a floating-point value
float Fixed::toFloat(void) const {
  return roundf(this->raw >> 8) + (float)(((this->raw % 256)) >> 8);
}

// NEW member function (Fixed::), converts the fixed-point value to an integer value
int Fixed::toInt(void) const {
  return roundf(this->raw >> 8);
}

// NEW overload of the insertion operator <<
std::ostream& operator<<(std::ostream& os, Fixed const & f)
{
  os << f.toFloat();
  return os;
}
