#include "Dog.hpp"

Dog::Dog() : Animal() {
  this->_type = "Dog";
  this->brain = new Brain();
  std::cout << "Dog         default constructor" << std::endl;
};

Dog::~Dog() {
  std::cout << "Dog         destructor" << std::endl;
  delete brain;
};

Brain* Dog::getBrain() {
  return this->brain;
}

void Dog::makeSound() const {
  std::cout << "Dog         says Ouaf Ouaf" << std::endl;
}
