#include "Zombie.hpp"
#include "newZombie.cpp"
#include "randomChump.cpp"

int	main()
{
  Zombie z("Created by constructor"); // stack
	z.announce();

  Zombie *z2 = newZombie("Created by newZombie"); // heap
  z2->announce();
  delete z2;

  randomChump("Created by randomChump"); // stack

  return (0);
}
