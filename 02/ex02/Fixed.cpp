#include "Fixed.hpp"

Fixed::Fixed() {
  this->raw = 0;
}

Fixed::Fixed(const int raw_) {
  this->raw = raw_ * 256;
}

Fixed::Fixed(const float raw_) {
  int raw_int = (int)(raw_);
  int raw_dec = roundf((raw_ - (int)raw_)*256);
  this->raw = raw_int * 256 + raw_dec;
}

// a new object is created as a copy of the existing object
Fixed::Fixed(const Fixed &obj) {
  *this = obj; // ?
}

// an already initialized object is assigned to a new value from another existing object
// copy assignment operator overload
Fixed& Fixed::operator = (Fixed const &obj) {
  if (this != &obj)
    this->raw = obj.getRawBits();
  return (*this);
}

Fixed::~Fixed() {
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
bool  Fixed::operator == (const Fixed &refOther ) const {
  return this->getRawBits() == refOther.getRawBits();
}

bool  Fixed::operator != (const Fixed &refOther) const {
  return this->getRawBits() != refOther.getRawBits();
}

bool  Fixed::operator >  (const Fixed &refOther) const {
  return this->getRawBits() > refOther.getRawBits();
}

bool  Fixed::operator >= (const Fixed &refOther) const {
  return this->getRawBits() >= refOther.getRawBits();
}

bool  Fixed::operator < (const Fixed &refOther) const {
  return this->getRawBits() < refOther.getRawBits();
}

bool  Fixed::operator <= (const Fixed &refOther) const {
  return this->getRawBits() <= refOther.getRawBits();
}

Fixed  Fixed::operator + (const Fixed &refOther) const {
  return Fixed(this->toFloat() + refOther.toFloat());
}

Fixed  Fixed::operator - (const Fixed &refOther) const {
  return Fixed(this->toFloat() - refOther.toFloat());
}

Fixed  Fixed::operator * (const Fixed &refOther) const {
  return Fixed(this->toFloat() * refOther.toFloat());
}

Fixed  Fixed::operator / (const Fixed &refOther) const {
  return Fixed(this->toFloat() / refOther.toFloat());
}

Fixed  Fixed::operator ++ (int) { // a++
  Fixed tmp(*this);
  tmp.raw = (this->raw)++;
  return tmp;
}

Fixed& Fixed::operator ++ (void) { // ++a
  ++(this->raw);
  return *this;
}

Fixed  Fixed::operator -- (int) {
  Fixed tmp(*this);
  tmp.raw = (this->raw)--;
  return tmp;
}

Fixed& Fixed::operator -- (void) {
  --(this->raw);
  return *this;
}

Fixed& Fixed::max (Fixed &ref1, Fixed &ref2) {
  if (ref1.toFloat() >= ref2.toFloat())
    return ref1;    
  return ref2;
}

Fixed& Fixed::max (const Fixed &ref1, const Fixed &ref2) {
  if (ref1.toFloat() >= ref2.toFloat())
    return (Fixed&)ref1;
  return (Fixed&)ref2;
}