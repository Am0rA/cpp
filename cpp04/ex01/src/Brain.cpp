/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/25 22:43:21 by itopchu       #+#    #+#                 */
/*   Updated: 2023/09/25 22:43:21 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	putMessage(YELLOW, "Default constructor of Brain is called", 1);
	for (int i = 0; i < 100; i++)
		this->ideas[i] = std::to_string(i);
}

Brain::Brain(const Brain& copy)
{
	putMessage(YELLOW, "Copy constructor of Brain is called", 1);
	*this = copy;
}

Brain::~Brain()
{
	putMessage(PURP, "Destructor of Brain is called" , 1);
}

Brain& Brain::operator=(const Brain& assign)
{
	if (this != &assign)
	{
		for (int i = 0; i < sizeof(assign.ideas); i++)
			ideas[i] = assign.ideas[i];
	}
	return *this;
}
