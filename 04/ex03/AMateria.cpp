#include "AMateria.hpp"

AMateria::AMateria() {
  this->type = "not defined";
  std::cout << "Materia     default constructor   (type = not defined)" << std::endl;
}

AMateria::AMateria(std::string const & type) {
  this->type = type;
  std::cout << "Materia     string  constructor   (type = " << type << ")" << std::endl;
}

AMateria::AMateria(AMateria const & src) {
  *this = src;
  std::cout << "Materia     copy    constructor   (type = " << type << ")" << std::endl;
  }

AMateria::~AMateria() {
  std::cout << "Materia     destructor            (type = " << type << ")" << std::endl;
}



std::string const & AMateria::getType() const {
  return this->type;
}

AMateria* AMateria::clone() const {
  std::cout << "Materia     clone                 (type = " << type << ")" << std::endl;
  return (AMateria*)this;
}

void AMateria::use(ICharacter& target) {
  std::cout << "AMateria " << this->type << " used on " << target.getName() << std::endl;
}

// While assigning a Materia to another, copying the type doesn’t make sense