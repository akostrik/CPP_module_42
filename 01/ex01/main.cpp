#include "Zombie.hpp"
#include "zombieHorde.cpp"


int	main()
{
  int N = 5;

  Zombie	*firstZombie = zombieHorde(N, "Robert");
  for (size_t i = 0; i < (size_t)N; i++)
		firstZombie[i].announce();
  delete [] firstZombie;

  return (0);
}
