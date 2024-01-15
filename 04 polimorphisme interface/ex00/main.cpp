#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
  std::cout << "Construstors tests:" << std::endl;
  Animal*      meta      = new Animal();       // 1 constructor
  Animal*      cat       = new Cat();          // 2 constructors
  Animal*      dog       = new Dog();          // 2 constructors
  WrongAnimal* wrongMeta = new WrongAnimal();  // 1 constructor
  WrongAnimal* wrongCat  = new WrongCat();     // 2 constructors

  std::cout << std::endl << "getType() tests:" << std::endl;
  std::cout << cat->getType() << std::endl;
  std::cout << dog->getType() << std::endl;

  std::cout << std::endl << "makeSound() tests:" << std::endl;
  meta->makeSound();
  cat->makeSound();
  dog->makeSound();
  // The WrongCat must output the WrongCat makeSound() only when used as a wrongCat
  wrongMeta->makeSound();
  wrongCat->makeSound();

  std::cout << std::endl << "destructors tests:" << std::endl;
  delete meta;                                        // 1 destructor
  delete cat;                                         // 2 destructors
  delete dog;                                         // 2 destructors
  delete wrongMeta;                                   // 1 destructor
  delete wrongCat;                                    // 1 destructor (but 2 constructors, no leaks)

  return 0;
}
