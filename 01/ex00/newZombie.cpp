#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
  Zombie *z2 = new Zombie(name);
  return (z2);
  // the same : return (new Zombie(name));
}
