#include "Cat.hpp"

Cat::Cat() : Animal() {
  this->type = "Cat";
  this->brain = new Brain();
  std::cout << "Cat         default constructor" << std::endl;
};


Cat::Cat(const Cat &ref) {
  std::cout << "Cat         copy    constructor" << std::endl;
  *this = ref;
};

Cat::~Cat() {
  std::cout << "Cat         destructor" << std::endl;
  delete this->brain; // delete brain[] ?
};

Cat& Cat::operator = (Cat const &ref) {
  if (this != &ref)
  {
    this->type  = ref.type;
    this->brain = new Brain(*ref.brain);

  }
  return *this;
};

Brain* Cat::getBrain() const {
  return this->brain;
};

void Cat::makeSound() const {
  std::cout << "Cat         says Miaou Miaou" << std::endl;
};
