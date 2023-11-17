#include "Brain.hpp"

Brain::Brain() {
  std::cout << "Brain       default constructor  (type not defined)" << std::endl;
  for (int i = 0; i < 100; i++) 
    this->ideas[i] = "idea" + i; //
};

Brain::Brain(const Brain &obj) {
  std::cout << "Brain       copy    constructor  (type " << this->_type << ")" << std::endl;
  *this = obj;
};

Brain& Brain::operator = (Brain const &obj) {
  if (this != &obj)
    for (int i = 0; i < 100; i++)
      this->ideas[i] = obj.ideas[i];
  return *this;
};

Brain::~Brain() {
  std::cout << "Brain       destructor            (type " << this->_type << ")" << std::endl;
  // for (int i = 0; i < 100; i++)
  //   delete 
};

