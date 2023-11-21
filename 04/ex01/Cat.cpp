#include "Cat.hpp"

Cat::Cat() : Animal() {
  this->_type = "Cat";
  this->_brain = new Brain();
  std::cout << "Cat         default constructor" << std::endl;
};

Cat::~Cat() {
  std::cout << "Cat         destructor" << std::endl;
  delete this->_brain; // delete _brain[] ?
};

Cat& Cat::operator = (Cat const &obj) {
  if (this != &obj)
  {
    this->_type  = obj._type;
    this->_brain = obj._brain;
  }
  return *this;
};

Brain* Cat::getBrain() const {
  return this->_brain;
};

void Cat::makeSound() const {
  std::cout << "Cat         says Miaou Miaou" << std::endl;
};

std::ostream& operator<<(std::ostream& os, Cat const &obj) {
  os << "I am Cat, my brain is: " << obj.getBrain() << std::endl;
  return os;
}