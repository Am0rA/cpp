#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie newZombie;

	if (name.empty())
		newZombie.setRandomName();
	else
		newZombie.setName(name);
	newZombie.announce();
}
