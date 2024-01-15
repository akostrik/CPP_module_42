 #include "WrongCat.hpp"


WrongCat::WrongCat() : WrongAnimal() {
  this->type = "WrongCat";
  std::cout << "WrongCat    default constructor  (type " << this->type << ")" << std::endl;
};

WrongCat::~WrongCat() {
  std::cout << "WrongCat    destructor            (type " << this->type << ")" << std::endl;
};



// The WrongCat must output the WrongCat makeSound() only when used as a wrongCat
void WrongCat::makeSound() const {
  std::cout << "WrongCat    says Miaou Miaou" << std::endl;
}
