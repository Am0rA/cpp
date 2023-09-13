/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 13:01:59 by itopchu       #+#    #+#                 */
/*   Updated: 2023/08/31 13:01:59 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <ctime>
# define BLUE "\033[34m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define C_RESET "\033[37m"
# define BOLD "\033[1m"
# define T_RESET "\033[0m"

class Zombie
{
	public:
		Zombie();
		~Zombie();
		void setName(std::string name);
		void setRandomName(void);
		void announce(void);
	private:
		std::string	_name;
};
Zombie *newZombie(std::string name);
void	randomChump(std::string name);

#endif