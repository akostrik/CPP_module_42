#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
  this->_type = "not defined";
  std::cout << "WrongAnimal default constructor  (type not defined)" << std::endl;
};

WrongAnimal::WrongAnimal(const WrongAnimal &obj) {
  *this = obj;
  std::cout << "WrongAnimal copy    constructor   (type " << this->_type << ")" << std::endl;
};

WrongAnimal& WrongAnimal::operator = (WrongAnimal const &obj) {
  this->_type = obj._type;
  std::cout << "WrongAnimal assignment operator   (type = " << this->type << ")" << std::endl;
  return *this;
};

WrongAnimal::~WrongAnimal() {
  std::cout << "WrongAnimal destructor            (type " << this->_type << ")" << std::endl;
};

// member functions

void WrongAnimal::makeSound( void ) const {
  std::cout << "WrongAnimal makes undefined sound (type " << this->_type << ")" << std::endl;
};

std::string WrongAnimal::getType(void) const {
  return this->_type;
};
