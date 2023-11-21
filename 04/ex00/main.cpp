#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
  std::cout << "Construstors tests:" << std::endl;
  const Animal*      meta      = new Animal();       // 1 constructor
  const Animal*      cat       = new Cat();          // 2 constructors
  const Animal*      dog       = new Dog();          // 2 constructors
  const WrongAnimal* wrongMeta = new WrongAnimal();  // 1 constructor
  const WrongAnimal* wrongCat  = new WrongCat();     // 2 constructors

  std::cout << std::endl << "getType() tests:" << std::endl;
  std::cout << cat->getType() << std::endl;
  std::cout << dog->getType() << std::endl;

  std::cout << std::endl << "makeSound() tests:" << std::endl;
  cat->makeSound();
  dog->makeSound();
  meta->makeSound();
  wrongMeta->makeSound();
  wrongCat->makeSound();

  std::cout << std::endl << "destructors tests:" << std::endl;
  delete meta;                                        // 1 destructor
  delete cat;                                         // 2 destructors
  delete dog;                                         // 2 destructors
  delete wrongMeta;                                   // 1 destructor
  delete wrongCat;                                    // 1 destructor (but 2 constructors, althought no leaks)

  return 0;
}
