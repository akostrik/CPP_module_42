#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

#define N 2

int main()
{
  // Animal test; // a compile error : variable type 'Animal' is an abstract class
  Animal *a[N];

  std::cout << "********** Creation of " << N << " animals:" << std::endl;
  for (int i = 0; i < N; i++) 
  {
    if (i % 2 == 0)
      a[i] = new Cat();
    else
      a[i] = new Dog();
    std::cout << std::endl;
  }

  std::cout << "********** Make sound the " << N << " animals:" << std::endl;
  for (int i = 0; i < N; i++)
    a[i]->makeSound();
  std::cout << std::endl;

  std::cout << "********** Desctruction of the " << N << " animals:" << std::endl;
  for (int i = 0; i < N; i++)
    delete a[i];
  std::cout << std::endl;

  ////////////////////////////////////////////////////////////
  std::cout << "********** Creation Cat cat1:" << std::endl;
  Cat * cat1 = new Cat();
  std::cout << "cat1        = " << cat1 << std::endl;
  std::cout << "ideas:      ";
  for (int i = 0; i < NB_IDEAS; i++)
    std::cout << cat1->getBrain()->getIdeas()[i] << " ";
  std::cout << std::endl << std::endl;

  std::cout << "********** Creation Cat cat2, deep copy of cat1, by copy constructor :" << std::endl;
  Cat *cat2;
  cat2 = new Cat(*cat1);
  std::cout << "cat2        = " << cat2 << std::endl;
  std::cout << "ideas:      ";
  for (int i = 0; i < NB_IDEAS; i++)
    std::cout << cat1->getBrain()->getIdeas()[i] << " ";
  std::cout << std::endl << std::endl;

  std::cout << "********** Modifying of the two first ideas of cat1:" << std::endl;
  cat1->getBrain()->getIdeas()[0] = "ID-01";
  cat1->getBrain()->getIdeas()[1] = "ID-02";
  std::cout << "cat1 ideas: ";
  for (int i = 0; i < NB_IDEAS; i++)
    std::cout << cat1->getBrain()->getIdeas()[i] << " ";
  std::cout << std::endl;
  std::cout << "cat2 ideas: ";
  for (int i = 0; i < NB_IDEAS; i++)
    std::cout << cat2->getBrain()->getIdeas()[i] << " ";
  std::cout << std::endl << std::endl;

  std::cout << "********** Modifying of the two first idea of cat2:" << std::endl;
  cat2->getBrain()->getIdeas()[0] = "ID-03";
  cat2->getBrain()->getIdeas()[1] = "ID-04";
  std::cout << "cat1 ideas: ";
  for (int i = 0; i < NB_IDEAS; i++)
    std::cout << cat1->getBrain()->getIdeas()[i] << " ";
  std::cout << std::endl;
  std::cout << "cat2 ideas: ";
  for (int i = 0; i < NB_IDEAS; i++)
    std::cout << cat2->getBrain()->getIdeas()[i] << " ";
  std::cout << std::endl << std::endl;

  std::cout << "********** Desctruction cat1 and cat2:" << std::endl;
  delete cat1;
  delete cat2;
  std::cout << std::endl;

  ////////////////////////////////////////////////////////////
  std::cout << "********** Creation Dog dog1:" << std::endl;
  Dog dog1;
  std::cout << "ideas:      ";
  for (int i = 0; i < NB_IDEAS; i++)
    std::cout << dog1.getBrain()->getIdeas()[i] << " ";
  std::cout << std::endl << std::endl;

  std::cout << "********** Creation Dog dog2, by dog2 = dog1 (deep copy):" << std::endl;
  Dog dog2 = dog1;
  std::cout << "ideas:      ";
  for (int i = 0; i < NB_IDEAS; i++)
    std::cout << dog2.getBrain()->getIdeas()[i] << " ";
  std::cout << std::endl << std::endl;

  std::cout << "********** Modifying of the two first ideas of dog1:" << std::endl;
  dog1.getBrain()->getIdeas()[0] = "ID-05";
  dog1.getBrain()->getIdeas()[1] = "ID-06";
  std::cout << "dog1 ideas: ";
  for (int i = 0; i < NB_IDEAS; i++)
    std::cout << dog1.getBrain()->getIdeas()[i] << " ";
  std::cout << std::endl;
  std::cout << "dog2 ideas: ";
  for (int i = 0; i < NB_IDEAS; i++)
    std::cout << dog2.getBrain()->getIdeas()[i] << " ";
  std::cout << std::endl << std::endl;

  std::cout << "********** Modifying of the two first ideas of dog2:" << std::endl;
  dog2.getBrain()->getIdeas()[0] = "ID-07";
  dog2.getBrain()->getIdeas()[1] = "ID-08";
  std::cout << "dog1 ideas: ";
  for (int i = 0; i < NB_IDEAS; i++)
    std::cout << dog1.getBrain()->getIdeas()[i] << " ";
  std::cout << std::endl;
  std::cout << "dog2 ideas: ";
  for (int i = 0; i < NB_IDEAS; i++)
    std::cout << dog2.getBrain()->getIdeas()[i] << " ";
  std::cout << std::endl << std::endl;


  std::cout << "********** return:" << std::endl;
  return 0;
}
