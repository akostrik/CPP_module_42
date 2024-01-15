#include "Cat.hpp"

Cat::Cat() : Animal() {
  this->type = "Cat";
  this->brain = new Brain();
  std::cout << "Cat         default constructor" << std::endl;
};

Cat::~Cat() {
  std::cout << "Cat         destructor" << std::endl;
  delete this->brain;
};

// The copy and assignment behaviors are like the subject requires
// The copy constructor should do a deep copy
Cat::Cat(const Cat &ref) {
  std::cout << "Cat         copy    constructor" << std::endl;
  *this = ref;
};

// The copy and assignment behaviors are like the subject requires
// The copy should be a deep copy
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
