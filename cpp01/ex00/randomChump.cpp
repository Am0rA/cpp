#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie newZombie;

	if (name.empty())
		newZombie.SetRandomName();
	else
		newZombie.SetName(name);
	newZombie.announce();
}
