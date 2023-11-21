#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

#define N 3

int main()
{
  // Animal *a[N];

  // std::cout << "Creation of " << N << " animals:" << std::endl;
  // for (int i = 0; i < N; i++)
  //   if (i % 2 == 0)
  //     a[i] = new Cat();
  //   else
  //     a[i] = new Dog();


  // std::cout << std::endl << "Make sound the animals:" << std::endl;
  // for (int i = 0; i < N; i++)
  //   a[i]->makeSound();


  std::cout << std::endl << "Test that the copies are deep ones:" << std::endl;
  Animal * const cat1 = new Cat();
  cat1->makeSound();
  std::cout << std::endl << "Test that the copies are deep ones:" << std::endl;
  Animal *cat2;
	cat2 = new Cat(*cat1);
  (void)cat2;
	//cat2->makeSound();

  // std::cout << std::endl << "1) I am cat1 (" << cat1 << "), my ideas are: ";
  // for (int i = 0; i < NB_IDEAS; i++)
  //   std::cout << cat1->getBrain()->getIdeas()[i] << " ";


  // std::cout << "\n\nDesctruction of the animals:" << std::endl;
  // for (int i = 0; i < N; i++)
  //   if (a[i]->getType() == "Cat")
  //     delete a[i];
  //   else
  //     delete a[i];

  // std::cout << "\n\nreturn" << std::endl;
  return 0;
}
