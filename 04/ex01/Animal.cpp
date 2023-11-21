#include "Animal.hpp"

Animal::Animal() {
  this->type = "not defined";
  std::cout << "Animal      default constructor   (type = not defined)" << std::endl;
};

Animal::Animal(const Animal &ref) {
  std::cout << "Animal      copy    constructor   (type = " << this->type << ")" << std::endl;
  *this = ref;
  // this->type = ref.type; ?
};

Animal& Animal::operator = (Animal const &ref) {
  this->type = ref.type;
  return *this;
};

Animal::~Animal() {
  std::cout << "Animal      destructor            (type = " << this->type << ") VIRTUAL" << std::endl;
};

// member functions

void Animal::makeSound () const {
  std::cout << "Animal      makes undefined sound (type = " << this->type << ") VIRTUAL" << std::endl;
}

std::string Animal::getType() const {
  return this->type;
}
