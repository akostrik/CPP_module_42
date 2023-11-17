#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
  const Animal* meta = new Animal();
  const Animal* cat  = new Cat();
  const Animal* dog  = new Dog();

  std::cout << dog->getType() << std::endl;
  std::cout << cat->getType() << std::endl;
  cat->makeSound();
  dog->makeSound();
  meta->makeSound();

  return 0;
}
