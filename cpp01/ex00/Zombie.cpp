#include "Zombie.hpp"
#include <cstdlib>
#include <vector>
#include <ctime>

// Constructors
Zombie::Zombie()
{

}

// Destructor
Zombie::~Zombie()
{
	std::cout << BLUE << this->_name << " is destructed" << C_RESET << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << BOLD << GREEN << this->_name << T_RESET << YELLOW << ": BraiiiiiiinnnzzzZ..." << C_RESET << T_RESET << std::endl;
}

void	Zombie::SetName(std::string name)
{
	this->_name = name;
}

void	Zombie::SetRandomName(void)
{
	const char	*names[] =
	{
        "Alice", "Bob", "Charlie", "David", "Ella",
        "Frank", "Grace", "Henry", "Isabella", "Jack"	
	};
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	int	randomIndex = std::rand() % 10;
	this->SetName(names[randomIndex]);
}
