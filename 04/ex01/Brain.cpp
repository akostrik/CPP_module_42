#include "Brain.hpp"

Brain::Brain() {
  std::cout << "Brain       default constructor" << std::endl;
  this->_ideas = new std::string[NB_IDEAS];
  for (int i = 0; i < NB_IDEAS; i++) 
    this->_ideas[i] = "idea!";
};


Brain::~Brain() {
  std::cout << "Brain       destructor" << std::endl;
  delete [] this->_ideas;
};

Brain::Brain(Brain const &ref) {
  std::cout << "Brain       copy    constructor" << std::endl;
  for (int i = 0; i < NB_IDEAS; i++)
    this->_ideas[i] = ref._ideas[i];
  // *this = ref; ?!
};

Brain& Brain::operator = (Brain const &ref) {
  for (int i = 0; i < NB_IDEAS; i++)
    this->_ideas[i] = ref._ideas[i];
    // this->_ideas[i] = std::string(ref._ideas[i]);
  return *this;
};

// member functions

std::string * Brain::getIdeas() { //const {
  return this->_ideas;
};
