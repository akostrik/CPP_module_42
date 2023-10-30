#include "Zombie.hpp"
#include "newZombie.cpp"
#include "randomChump.cpp"

int	main()
{
  Zombie *z2;
  z2 = new Zombie("Created by Zombie()    *z");
  z2->announce();
  delete z2;

  Zombie *z4;
  z4 = newZombie("Created by newZombie   *z");
  z4->announce();
  delete z4;

  Zombie *z6;
  z6 = randomChump("Created by randomChump *z");
  delete z6;

  return (0);
}

//  leasks = allocations on the stack (?)
//  Zombie z1 = *(newZombie("Created by Zombie()     z"));
//  z1.announce();
//  delete z1; // expression must be a pointer
//  delete &z1; // Invalid free()
//  Zombie z3 = *(newZombie("Created by newZombie    z"));
//  z3.announce();
//  Zombie z5 = *(randomChump("Created by randomChump  z"));
