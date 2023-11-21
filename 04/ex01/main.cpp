#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

#define N 3

int main()
{
  Animal *a[N];

  std::cout << "*** Creation of " << N << " animals:" << std::endl;
  for (int i = 0; i < N; i++) 
  {
    if (i % 2 == 0)
      a[i] = new Cat();
    else
      a[i] = new Dog();
    std::cout << std::endl;
  }

  std::cout << "*** Make sound the " << N << " animals:" << std::endl;
  for (int i = 0; i < N; i++)
    a[i]->makeSound();
  std::cout << std::endl;

  std::cout << "*** Desctruction of the " << N << " animals:" << std::endl;
  for (int i = 0; i < N; i++)
    delete a[i];
  std::cout << std::endl;

  std::cout << "*** Creation Cat cat1:" << std::endl;
  Cat * const cat1 = new Cat();
  std::cout << "cat1        = " << cat1 << std::endl;
  std::cout << "ideas:      ";
  for (int i = 0; i < NB_IDEAS; i++)
    std::cout << cat1->getBrain()->getIdeas()[i] << " ";
  std::cout << std::endl << std::endl;

  std::cout << "*** Creation Cat cat2 - copy of cat1:" << std::endl;
  Cat *cat2;
  cat2 = new Cat(*cat1);
  std::cout << "cat2        = " << cat2 << std::endl;
  std::cout << "ideas:      ";
  for (int i = 0; i < NB_IDEAS; i++)
    std::cout << cat1->getBrain()->getIdeas()[i] << " ";
  std::cout << std::endl << std::endl;

  std::cout << "*** Modifying of the two first ides of cat1:" << std::endl;
  cat1->getBrain()->getIdeas()[0] = "NEW1!";
  cat1->getBrain()->getIdeas()[1] = "NEW2!";
  std::cout << "cat1 ideas: ";
  for (int i = 0; i < NB_IDEAS; i++)
    std::cout << cat1->getBrain()->getIdeas()[i] << " ";
  std::cout << std::endl;
  std::cout << "cat2 ideas: ";
  for (int i = 0; i < NB_IDEAS; i++)
    std::cout << cat2->getBrain()->getIdeas()[i] << " ";
  std::cout << std::endl << std::endl;

  std::cout << "*** Modifying of the two first ides of the copy:" << std::endl;
  cat2->getBrain()->getIdeas()[0] = "IDEA1";
  cat2->getBrain()->getIdeas()[1] = "IDEA2";
  std::cout << "cat1 ideas: ";
  for (int i = 0; i < NB_IDEAS; i++)
    std::cout << cat1->getBrain()->getIdeas()[i] << " ";
  std::cout << std::endl;
  std::cout << "cat2 ideas: ";
  for (int i = 0; i < NB_IDEAS; i++)
    std::cout << cat2->getBrain()->getIdeas()[i] << " ";
  std::cout << std::endl << std::endl;

  std::cout << "*** Desctruction cat1 qnd cqt2:" << std::endl;
  delete cat1;
  delete cat2;

  return 0;
}
