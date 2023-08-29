#include "Zombie.hpp"

int	main(void)
{
	Zombie	*Zombie;

	Zombie = newZombie("Choko");
	Zombie->announce();
	randomChump("Chump");
	randomChump("");
	delete (Zombie);
	return (0);
}