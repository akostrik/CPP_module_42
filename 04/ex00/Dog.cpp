#include "Dog.hpp"

Dog::Dog() : Animal() {
  std::cout << "Dog    default constructor  (type " << this->_type << ")" << std::endl;
  this->_type = "Dog";
};

Dog::~Dog() {
  std::cout << "Dog    default destructor   (type " << this->_type << ")" << std::endl;
};

void Dog::makeSound() const {
  std::cout << "Dog    says Ouaf Ouaf" << std::endl;
}
