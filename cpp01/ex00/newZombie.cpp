#include "Zombie.hpp"

Zombie	*newZombie(std::string name)
{
	Zombie	*toDelete = new (Zombie);
	toDelete->SetName(name);
	return (toDelete);
}