#include <cctype>
#include <string>
#include <iostream>
#include <cstring>

#include "Zombie.hpp"

int	main()
{
  Zombie *z = new Zombie();

  z->announce();

  delete z;
  return (0);
}