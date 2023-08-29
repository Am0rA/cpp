#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*Horde = NULL;
	if (N <= 0)
		return (Horde);
	Horde = new Zombie[N];
	for (int i = 0; i < N; i++)
		Horde[i].SetName(name);
	return (Horde);
}