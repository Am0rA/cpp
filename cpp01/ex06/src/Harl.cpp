/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 13:05:42 by itopchu       #+#    #+#                 */
/*   Updated: 2023/08/31 13:05:42 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Harl.hpp>

Harl::Harl(){}

Harl::~Harl(){}

void	Harl::debug(void)
{
	std::cout << BLUE;
	std::cout << "╔═══════════════════════════════════════╗" << std::endl;
	std::cout << "║                 DEBUG                 ║" << std::endl;
	std::cout << "╚═══════════════════════════════════════╝" << std::endl;
	std::cout << WHITE;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << GREEN;
	std::cout << "╔═══════════════════════════════════════╗" << std::endl;
	std::cout << "║                 INFO                  ║" << std::endl;
	std::cout << "╚═══════════════════════════════════════╝" << std::endl;
	std::cout << WHITE;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;;
}

void	Harl::warning(void)
{
	std::cout << YELLOW;
	std::cout << "╔═══════════════════════════════════════╗" << std::endl;
	std::cout << "║                WARNING                ║" << std::endl;
	std::cout << "╚═══════════════════════════════════════╝" << std::endl;
	std::cout << WHITE;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;;
}

void	Harl::error(void)
{
	std::cout << RED;
	std::cout << "╔═══════════════════════════════════════╗" << std::endl;
	std::cout << "║                 ERROR                 ║" << std::endl;
	std::cout << "╚═══════════════════════════════════════╝" << std::endl;
	std::cout << WHITE;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;;
}

void	Harl::def(void)
{
	std::cout << GRAY;
	std::cout << "╔═══════════════════════════════════════╗" << std::endl;
	std::cout << "║                DEFAULT                ║" << std::endl;
	std::cout << "╚═══════════════════════════════════════╝" << std::endl;
	std::cout << WHITE;
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

void	Harl::complain(std::string level)
{
	int	lvl = -1;

	for (size_t i = 0; i < level.length(); i++)
		level[i] = tolower(level[i]);
	std::string _levels[] = {
		"debug",
		"info",
		"warning",
		"error"
	};
	for (int i = 0; i < 4; i++)
	{
		if (_levels[i] == level)
		{
			lvl = i;
			break ;
		}
	}
	switch (lvl)
	{
		case 0:
			this->debug();
			this->info();
			this->warning();
			this->error();
			break ;
		case 1:
			this->info();
			this->warning();
			this->error();
			break ;
		case 2:
			this->warning();
			this->error();
			break ;
		case 3:
			this->error();
			break;
		default:
			this->def();
			break;
	}
}

