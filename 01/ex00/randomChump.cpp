#include "Zombie.hpp"

Zombie* randomChump(std::string name)
{
  Zombie *z = new Zombie(name);
  z->announce();
  return (z);
}