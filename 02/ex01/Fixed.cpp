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
  this->fpv = 0;
  this->n = 8;
}

// NEW converts p to the corresponding fpv
// INT_MAX ?
Fixed::Fixed(int const _fpv) {
  std::cout << "Int constructor called" << std::endl;
  this->fpv = _fpv * 100000000;
  this->n = 8;
}

// NEW converts p to the corresponding fpv
Fixed::Fixed(float const _fpv) {
  std::cout << "Float constructor called" << std::endl;
  this->n = nb_decimal_figures(_fpv);
  this->fpv = roundf(_fpv * pow(10, this->n));
}

// a new object is created as a copy of the existing object
Fixed::Fixed(const Fixed &obj) {
  std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

// an already initialized object is assigned to a new value from another existing object
Fixed& Fixed::operator = (Fixed const &obj) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &obj)
  {
    this->fpv = obj.getRawBits();
    this->n = 8;
  }
  return (*this);
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
};

int Fixed::getRawBits(void) const {
  return this->fpv;
}

void Fixed::setRawBits(const int _fpv) {
	this->fpv = _fpv;
}

// NEW member function (Fixed::), converts the fixed-point value to a floating-point value
float Fixed::toFloat(void) const {
  return roundf(this->fpv / pow(10,this->n)) + ((float)(this->fpv % pow(10,this->n))) / pow(10,this->n);
}

// NEW member function (Fixed::), converts the fixed-point value to an integer value
int Fixed::toInt(void) const {
  return roundf(this->fpv /  pow(10,this->n));
}

// NEW overload of the insertion operator <<
std::ostream& operator<<(std::ostream& os, Fixed const & f)
{
  os << f.toFloat();
  return os;
}
