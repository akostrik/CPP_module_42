#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
  std::cout << "Ice         default constructor" << std::endl;
}

Ice::Ice(Ice const & src) : AMateria("ice") {
  *this = src;
  // std::cout << "* Ice: materia is copied *" << std::endl;
}

Ice&   Ice::operator=(const Ice& ref) {
  this->type = ref.type;
  std::cout << "Ice         assignment operator" << std::endl;
  return *this;
}

Ice::~Ice() {
  std::cout << "Ice         destructor" << std::endl;
}



// returns a new instance of the same type
AMateria* Ice::clone() const {
  std::cout << "Ice         clone" << std::endl;
  return (new Ice(*this));
}

void Ice::use(ICharacter& target) {
  std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}