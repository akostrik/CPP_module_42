#include "Animal.hpp"

Animal::Animal() {
  this->_type = "not defined";
  std::cout << "Animal      default constructor   (type = not defined)" << std::endl;
};

Animal::Animal(const Animal &obj) {
  std::cout << "Animal      copy    constructor   (type = " << this->_type << ")" << std::endl;
  *this = obj;
};

Animal& Animal::operator = (Animal const &obj) {
  if (this != &obj)
    this->_type = obj._type;
  return *this;
};

Animal::~Animal() {
  std::cout << "Animal      destructor    (type = " << this->_type << ") VIRTUAL" << std::endl;
};

// member functions

void Animal::makeSound( void ) const {
  std::cout << "Animal      makes undefined sound (type = " << this->_type << ") VIRTUAL" << std::endl;
} // lishnee ?

std::string Animal::getType(void) const {
  return this->_type;
}
Brain* Animal::getBrain() {
  return NULL;
};