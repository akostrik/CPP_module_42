#include "Animal.hpp"

Animal::Animal() {
  this->_type = "not defined";
  std::cout << "Animal      default constructor   (type = not defined)" << std::endl;
};

Animal::Animal(const Animal &ref) {
  std::cout << "Animal      copy    constructor   (type = " << this->_type << ")" << std::endl;
  *this = ref;
  // this->_type = ref._type; ?
};

Animal& Animal::operator = (Animal const &ref) {
  this->_type = ref._type;
  return *this;
};

Animal::~Animal() {
  std::cout << "Animal      destructor            (type = " << this->_type << ") VIRTUAL" << std::endl;
};

// member functions

void Animal::makeSound () const {
  std::cout << "Animal      makes undefined sound (type = " << this->_type << ") VIRTUAL" << std::endl;
}

std::string Animal::getType() const {
  return this->_type;
}
