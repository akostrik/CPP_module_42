#include "Cat.hpp"

Cat::Cat() : Animal() {
  this->_type = "Cat";
  this->brain = new Brain();
  std::cout << "Cat         default constructor" << std::endl;
};

Cat::~Cat() {
  std::cout << "Cat         destructor" << std::endl;
  delete brain;
};

Cat& Cat::operator = (Cat const &obj) {
  if (this != &obj)
  {
    this->_type = obj._type;
    for (int i = 0; i < 100; i++)
      this->brain->getIdeas()[i] = obj.getBrain()->getIdeas()[i];
  }
  return *this;
};

Brain* Cat::getBrain() { // 'this' argument to member function 'getBrain' has type 'const Cat', but function is not marked const
  return this->brain;
};

void Cat::makeSound() const {
  std::cout << "Cat         says Miaou Miaou" << std::endl;
};

