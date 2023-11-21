#include "Cat.hpp"

Cat::Cat() : Animal() {
  this->_type = "Cat";
  this->_brain = new Brain();
  std::cout << "Cat         default constructor" << std::endl;
};


Cat::Cat(const Cat &ref) {
  std::cout << "Cat         copy    constructor" << std::endl;
  *this = ref;
};

Cat::~Cat() {
  std::cout << "Cat         destructor" << std::endl;
  delete this->_brain; // delete _brain[] ?
};

Cat& Cat::operator = (Cat const &ref) {
  if (this != &ref)
  {
    this->_type  = ref._type;
    this->_brain = new Brain(*ref._brain);

  }
  return *this;
};

Brain* Cat::getBrain() const {
  return this->_brain;
};

void Cat::makeSound() const {
  std::cout << "Cat         says Miaou Miaou" << std::endl;
};
