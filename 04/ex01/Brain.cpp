#include "Brain.hpp"

Brain::Brain() {
  std::cout << "Brain       default constructor" << std::endl;
  for (int i = 0; i < 100; i++) 
    this->ideas[i] = "idea!";
};

Brain::Brain(const Brain &obj) {
  std::cout << "Brain       copy    constructor" << std::endl;
  *this = obj;
};

Brain& Brain::operator = (Brain const &obj) {
  if (this != &obj)
    for (int i = 0; i < 100; i++)
      this->ideas[i] = obj.ideas[i];
  return *this;
};

Brain::~Brain() {
  std::cout << "Brain       destructor" << std::endl;
};

std::string* Brain::getIdeas() {
  return this->ideas;
};

