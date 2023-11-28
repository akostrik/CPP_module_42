#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
  std::cout << "Cure        default constructor" << std::endl;
}

Cure::Cure(Cure const & src) : AMateria("cure") {
  *this = src;
  std::cout << "Cure        string  constructor" << std::endl;
}

Cure& Cure::operator=(const Cure& ref) {
  this->type = ref.type;
  std::cout << "Cure        assignment operator" << std::endl;
  return *this;
}

Cure::~Cure() {
  std::cout << "Cure        destructor" << std::endl;
}



AMateria* Cure::clone() const {
  std::cout << "Cure        clone" << std::endl;
  return (new Cure(*this));
}

void Cure::use(ICharacter& target) {
  std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}