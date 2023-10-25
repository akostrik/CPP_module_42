#include "Zombie.hpp"
#include "newZombie.cpp"
#include "randomChump.cpp"

int	main()
{
  Zombie *z1;	
  Zombie *z2;
  Zombie *z3;

  z1 = new Zombie("Jan");
  z1->announce();
  delete z1;

  z2 = newZombie("Jacques");
  z2->announce();
  delete z2;

  z3 = randomChump("Paul");
  delete z3;

  return (0);
}