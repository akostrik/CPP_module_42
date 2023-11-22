#include "Brain.hpp"

Brain::Brain() {
  std::cout << "Brain       default constructor" << std::endl;
  this->ideas = new std::string[NB_IDEAS];
  for (int i = 0; i < NB_IDEAS; i++) 
    this->ideas[i] = "idea!";
};

Brain::~Brain() {
  std::cout << "Brain       destructor" << std::endl;
  delete [] this->ideas;
};

Brain::Brain(Brain const &ref) {
  std::cout << "Brain       copy    constructor" << std::endl;
  *this = ref;
};

Brain& Brain::operator = (Brain const &ref) {
  this->ideas = new std::string[NB_IDEAS];
  for (int i = 0; i < NB_IDEAS; i++)
    this->ideas[i] = ref.ideas[i];
  return *this;
};

// member functions

std::string * Brain::getIdeas() {
  return this->ideas;
};
