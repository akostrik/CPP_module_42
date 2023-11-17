 #include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
  this->_type = "WrongCat";
  std::cout << "WrongCat    default constructor  (type " << this->_type << ")" << std::endl;
};

WrongCat::~WrongCat() {
  std::cout << "WrongCat    destructor           (type " << this->_type << ")" << std::endl;
};

void WrongCat::makeSound() const {
  std::cout << "WrongCat    says Miaou Miaou" << std::endl;
}
