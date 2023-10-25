#include <cctype>
#include <string>
#include <iostream>
#include <cstring>

// #include "Zombie.hpp"
#include "newZombie.cpp"
#include "randomChump.cpp"

int	main()
{
  Zombie *z = newZombie("Tom");

  z->announce();

  delete z;
  return (0);
}