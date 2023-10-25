#include "Zombie.hpp"

// version list
// but only a single allocatoin is allowed
// std::list <Zombie *> lst;
// for (int i = 0; i < N; i++)
//   lst.push_back(new Zombie(name));
// return lst.front();

// version list assign
// std::list <Zombie *> lst;
// lst.assign(N, new Zombie(name));
// return lst.front();

// version arr
// in the main only arr[0] assissible
// Zombie *arr[N];
// for (int i = 0; i < N; i++)
//   arr[i] = new Zombie(name);
// return arr[0];

// version arr
// in the main only arr[0] assissible
// Zombie** arr = (Zombie **)::operator new(N * sizeof(Zombie *));
// for (int i = 0; i < N; i++)
//   arr[i] = new Zombie(name);
// return arr[0];

Zombie* zombieHorde(int N, std::string name)
{
 	Zombie	*zombieHorde = new Zombie[N];

	for (int i = 0; i < N; i++)
		zombieHorde[i].setName(name);
	return (zombieHorde);
}
