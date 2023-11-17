#include "Cat.hpp"

Cat::Cat() : Animal() {
  this->_type = "Cat";
  this->brain = new Brain();
  std::cout << "Cat         default constructor  (type " << this->_type << ")" << std::endl;
};

Cat::~Cat() {
  // delete brain
  std::cout << "Cat         destructor            (type " << this->_type << ")" << std::endl;
};

void Cat::makeSound() const {
  std::cout << "Cat         says Miaou Miaou" << std::endl;
}
