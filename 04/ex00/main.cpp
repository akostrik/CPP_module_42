#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
  Animal* meta = new Animal();
  Animal* cat    = new Cat();
  Animal* dog    = new Dog();

  std::cout << dog->getType() << std::endl;
  std::cout << cat->getType() << std::endl;
  cat->makeSound();
  dog->makeSound();
  meta->makeSound();

  return 0;
}
