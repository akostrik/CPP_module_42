#include "Dog.hpp"

Dog::Dog() : Animal() {
  this->_type = "Dog";
  std::cout << "Dog         default constructor  (type " << this->_type << ")" << std::endl;
};

Dog::~Dog() {
  std::cout << "Dog         destructor            (type " << this->_type << ")" << std::endl;
};

void Dog::makeSound() const {
  std::cout << "Dog         says Ouaf Ouaf" << std::endl;
}
