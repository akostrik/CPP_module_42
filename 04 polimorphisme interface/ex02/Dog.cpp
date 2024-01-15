#include "Dog.hpp"

Dog::Dog() : Animal() {
  this->type = "Dog";
  try {
    this->brain = new Brain();
  } catch (const std::bad_alloc& e) {
    std::cout << "Memory Allocation is failed : " << e.what() << std::endl;
  }
  std::cout << "Dog         default constructor" << std::endl;
};

Dog::~Dog() {
  std::cout << "Dog         destructor" << std::endl;
  delete this->brain;
};

Dog::Dog(const Dog &ref) {
  std::cout << "Dog         copy    constructor" << std::endl;
  *this = ref;
};

Dog& Dog::operator = (Dog const &ref) {
  this->type  = ref.type;
  this->brain = new Brain(*ref.brain);
  std::cout << "Dog         assignment operator" << std::endl;
  return *this;
};

Brain* Dog::getBrain() const {
  return this->brain;
}

void Dog::makeSound() const {
  std::cout << "Dog         says Ouaf Ouaf" << std::endl;
}
