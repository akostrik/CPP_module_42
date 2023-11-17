#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define N = 8;

int main()
{
  Animal a[N];

  for (int i = 0; i < N; i++)
    if (i % 2 == 0)
      a[i] = new Cat();
    else
      a[i] = new Dog();

  for (int i = 0; i < N; i++)
    a[i].makeSound();

  for (int i = 0; i < N; i++)
    if (a[i].getType() == "Cat")
      delete a[i];
    else
      delete a[i];

  return 0;
}
