#include "Dog.hpp"

Dog::Dog() : Animal() {
  this->_type = "Dog";
  this->brain = new Brain();
  std::cout << "Dog         default constructor  (type " << this->_type << ")" << std::endl;
};

Dog::~Dog() {
  std::cout << "Dog         destructor            (type " << this->_type << ")" << std::endl;
  // delete brain
};

void Dog::makeSound() const {
  std::cout << "Dog         says Ouaf Ouaf" << std::endl;
}
