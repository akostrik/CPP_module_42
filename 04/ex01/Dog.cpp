#include "Dog.hpp"

Dog::Dog() : Animal() {
  this->_type = "Dog";
  this->_brain = new Brain();
  std::cout << "Dog         default constructor" << std::endl;
};

Dog::~Dog() {
  std::cout << "Dog         destructor" << std::endl;
  delete _brain;
};

Brain* Dog::getBrain() {
  return this->_brain;
}

void Dog::makeSound() const {
  std::cout << "Dog         says Ouaf Ouaf" << std::endl;
}
