#include "Zombie.hpp"

int	main(void)
{
	Zombie	*Horde;
	int		size = 50;

	Horde = zombieHorde(size, "Golden");
	for (int i = 0; i < size; i++)
	{
		std::cout << "num: " << i << " ";
		Horde[i].announce();
	}
	delete [] Horde;
	return (0);
}