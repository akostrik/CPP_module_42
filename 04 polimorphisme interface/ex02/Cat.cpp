#include "Cat.hpp"

Cat::Cat() : Animal() {
  this->type = "Cat";
  try {
    this->brain = new Brain();
  } catch (const std::bad_alloc& e) {
    std::cout << "Memory Allocation is failed : " << e.what() << std::endl; // partout
	}
  std::cout << "Cat         default constructor" << std::endl;
};

Cat::~Cat() {
  std::cout << "Cat         destructor" << std::endl;
  delete this->brain;
};

Cat::Cat(const Cat &ref) {
  std::cout << "Cat         copy    constructor" << std::endl;
  *this = ref;
};

Cat& Cat::operator = (Cat const &ref) {
  this->type  = ref.type;
  this->brain = new Brain(*ref.brain);
  std::cout << "Cat         assignment operator" << std::endl;
  return *this;
};

Brain* Cat::getBrain() const {
  return this->brain;
};

void Cat::makeSound() const {
  std::cout << "Cat         says Miaou Miaou" << std::endl;
};
