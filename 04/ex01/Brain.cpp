#include "Brain.hpp"

Brain::Brain() {
  std::cout << "Brain       default constructor" << std::endl;
  const
  for (int i = 0; i < NB_IDEAS; i++) 
    this->ideas[i] = "idea!";
};

Brain::Brain(const Brain &obj) {
  std::cout << "Brain       copy    constructor" << std::endl;
  *this = obj;
};

Brain& Brain::operator = (Brain const &obj) {
  if (this != &obj)
    for (int i = 0; i < NB_IDEAS; i++)
      this->ideas[i] = std::string(obj.ideas[i]);
  return *this;
};

Brain::~Brain() {
  std::cout << "Brain       destructor" << std::endl;
};

std::string * Brain::getIdeas() const {
  return this->ideas;
};

std::ostream& operator<<(std::ostream& os, Brain const &obj) {
  for (int i = 0; i < NB_IDEAS; i++)
    os << obj.getIdeas()[i] << " ";
  return os;
}
