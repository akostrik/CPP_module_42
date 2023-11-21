#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

#define N 3

int main()
{
  Animal *a[N];

  std::cout << "Creation of " << N << " animals:" << std::endl;
  for (int i = 0; i < N; i++)
    if (i % 2 == 0)
      a[i] = new Cat();
    else
      a[i] = new Dog();

  std::cout << std::endl << "Make sound the animals:" << std::endl;
  for (int i = 0; i < N; i++)
    a[i]->makeSound();

  std::cout << std::endl << "Test that the copies are deep copies:" << std::endl;
  std::cout              << "1) I am the original, I am a " << a[0]->getType() << ", my ideas are: ";
  for (int i = 0; i < NB_IDEAS; i++)
    std::cout << a[0]->getBrain()->getIdeas()[i] << " ";
  Animal *copy = a[0];
  std::cout << std::endl << "1) I am a copy      , I am a " << copy->getType() << ", my ideas are: ";
  for (int i = 0; i < NB_IDEAS; i++)
    std::cout << copy->getBrain()->getIdeas()[i] << " ";
  copy->getBrain()->getIdeas()[0] = "IDEA2!";
  a[0]->getBrain()->getIdeas()[0] = "IDEA1!";
  std::cout << std::endl << "2) I am the original, I am a " << a[0]->getType() << ", my ideas are: ";
  for (int i = 0; i < NB_IDEAS; i++)
    std::cout << a[0]->getBrain()->getIdeas()[i] << " ";
  std::cout << std::endl << "2) I am a copy      , I am a " << copy->getType() << ", my ideas are: ";
  for (int i = 0; i < NB_IDEAS; i++)
    std::cout << copy->getBrain()->getIdeas()[i] << " ";

  std::cout << "\n\nDesctruction of the animals:" << std::endl;
  for (int i = 0; i < N; i++)
    if (a[i]->getType() == "Cat")
      delete a[i];
    else
      delete a[i];

  return 0;
}
