#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
  this->type = "not defined";
  std::cout << "WrongAnimal default constructor  (type not defined)" << std::endl;
};

WrongAnimal::WrongAnimal(const WrongAnimal &ref) {
  *this = ref;
  std::cout << "WrongAnimal copy    constructor   (type " << this->type << ")" << std::endl;
};

WrongAnimal& WrongAnimal::operator = (WrongAnimal const &ref) {
  this->type = ref.type;
  return *this;
};

WrongAnimal::~WrongAnimal() {
  std::cout << "WrongAnimal destructor            (type " << this->type << ")" << std::endl;
};



void WrongAnimal::makeSound( void ) const {
  std::cout << "WrongAnimal makes undefined sound (type " << this->type << ")" << std::endl;
};


std::string WrongAnimal::getType(void) const {
  return this->type;
};
