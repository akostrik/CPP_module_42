#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << BYEL << "Default constructor called" << DEFCOLO << std::endl;
	this->_num = 0;
}


// * A new object is created as a copy of the existing object
//	this->_num = obj.getRawBits();
Fixed::Fixed(const Fixed &obj)
{
	std::cout << BMAG << "Copy constructor called" << DEFCOLO << std::endl;
	*this = obj;
}


// An already initialized object is assigned to a new value from another existing object
Fixed &Fixed::operator = (Fixed const &obj)
{
	std::cout << BCYN << "Copy assignment operator called" << DEFCOLO << std::endl;
	this->_num = obj.getRawBits();
	return (*this);
}


~Fixed() {
	std::cout << BYEL << "Destructor called" << DEFCOLO << std::endl;

};


void Fixed::setRawBits(int const raw)
{
	this->_num = raw;
}
