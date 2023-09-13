/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 13:05:19 by itopchu       #+#    #+#                 */
/*   Updated: 2023/08/31 13:05:19 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Harl.hpp>

Harl::Harl(){}

Harl::~Harl(){}

void	Harl::debug(void)
{
	std::cout << BLUE << "Debug: " << WHITE << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << GREEN << "Info: " << WHITE << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;;
}

void	Harl::warning(void)
{
	std::cout << YELLOW << "Warning: " << WHITE << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;;
}

void	Harl::error(void)
{
	std::cout << RED << "Error: " << WHITE << "This is unacceptable! I want to speak to the manager now." << std::endl;;
}

void	Harl::def(void)
{
	std::cout << GRAY << "Default: " << WHITE << "Harl only complains with dEbUG InFo WArniNG eRROr" << std::endl;
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
			break;
		case 1:
			this->info();
			break;
		case 2:
			this->warning();
			break;
		case 3:
			this->error();
			break;
		default:
			this->def();
			break;
	}
}

