#include "Animal.hpp"

Animal::Animal() {
  std::cout << "Anonymus default Animal constructor called" << std::endl;
  this->type = "";
};

Animal::Animal(std::string type_) {
  std::cout << type_ << " string Animal constructor called" << std::endl;
  this->type = "";
};

// a new object is created as a copy of the existing object
Animal::Animal(const Animal &obj) {
  std::cout << obj.type << " copy Animal constructor called" << std::endl;
  *this = obj;
};

// an already initialized object is assigned to a new value from another existing object
Animal& Animal::operator = (Animal const &obj) {
  if (this != &obj) {
    this->type = obj.type;
  }
  return (*this);
};

Animal::~Animal() {
  std::cout << this->type << " Animal destructor called" << std::endl;
};

std::string Animal::getType(void) const {
  std::cout << "getType member function called" << std::endl;
  return this->type;
}
