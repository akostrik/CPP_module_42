#include "Cat.hpp"

Cat::Cat() : Animal() {
  this->_type = "Cat";
  std::cout << "Cat         default constructor  (type " << this->_type << ")" << std::endl;
};

Cat::~Cat() {
  std::cout << "Cat         destructor            (type " << this->_type << ")" << std::endl;
};

void Cat::makeSound() const {
  std::cout << "Cat         says Miaou Miaou" << std::endl;
}
