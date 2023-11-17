#include "Cat.hpp"

Cat::Cat() : Animal() {
  std::cout << "Cat    default constructor  (type " << this->_type << ")" << std::endl;
  this->_type = "Cat";
};

Cat::~Cat() {
  std::cout << "Cat    default destructor   (type " << this->_type << ")" << std::endl;
};

void Cat::makeSound() const {
  std::cout << "Cat    says Miaou Miaou" << std::endl;
}
