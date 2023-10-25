#include <cctype>
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <algorithm>

#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
  Zombie *z = new Zombie(name);
  return (z);
}