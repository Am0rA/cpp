/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 13:00:48 by itopchu       #+#    #+#                 */
/*   Updated: 2023/08/31 13:00:48 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstdlib>
#include <vector>
#include <ctime>

Zombie::Zombie()
{

}

Zombie::~Zombie()
{
	std::cout << BLUE << this->_name << " is destructed" << C_RESET << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << BOLD << GREEN << this->_name << T_RESET << YELLOW << ": BraiiiiiiinnnzzzZ..." << C_RESET << T_RESET << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
}

void	Zombie::setRandomName(void)
{
	const char	*names[] =
	{
        "Alice", "Bob", "Charlie", "David", "Ella",
        "Frank", "Grace", "Henry", "Isabella", "Jack"	
	};
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	int	randomIndex = std::rand() % 10;
	this->setName(names[randomIndex]);
}
