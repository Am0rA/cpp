/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongAnimal.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/20 22:11:42 by itopchu       #+#    #+#                 */
/*   Updated: 2023/09/20 22:11:42 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// Form
WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
	putMessage(YELLOW, "Default constructor of WrongAnimal is called", 1);
}

WrongAnimal::WrongAnimal(const std::string type) : _type(type)
{
	putMessage(YELLOW, "Name constructor of WrongAnimal is called", 1);
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy)
{
	putMessage(YELLOW, "Copy constructor of WrongAnimal is called", 1);
	*this = copy;
}

WrongAnimal & WrongAnimal::operator=(const WrongAnimal& assign)
{
	this->_type = assign.getType();
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	putMessage(PURP, "Destructor of " , 0);
	putMessage(PURP, getType() , 0);
	putMessage(PURP, " is called" , 1);
}

// Member functions
void	WrongAnimal::makeSound() const
{
	putMessage(L_BLUE, "What does a JellyFish, Starfish, Worm or Snail say? Nothing :)", 1);
}

std::string	WrongAnimal::getType() const
{
	return (this->_type);
}
