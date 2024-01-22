#include "Animal.hpp"

Animal::Animal() {
  this->type = "not defined";
  std::cout << "Animal      default constructor  (type not defined)" << std::endl;
};

Animal::Animal(const Animal &obj) {
  *this = obj;
  std::cout << "Animal      copy    constructor  (type " << this->type << ")" << std::endl;
};

Animal& Animal::operator = (Animal const &obj) {
  this->type = obj.type;
  std::cout << "Animal      assignment operator   (type = " << this->type << ")" << std::endl;
  return *this;
};

Animal::~Animal() {
  std::cout << "Animal      destructor            (type " << this->type << ")" << std::endl;
};



void Animal::makeSound( void ) const {
  std::cout << "Animal      makes undefined sound (type " << this->type << ")" << std::endl;
};

std::string Animal::getType(void) const {
  return this->type;
};
