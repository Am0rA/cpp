/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/20 21:21:14 by itopchu       #+#    #+#                 */
/*   Updated: 2023/09/20 21:21:14 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Form
Animal::Animal() : _type("Animal")
{
	putMessage(YELLOW, "Default constructor of Animal is called", 1);
}

Animal::Animal(const std::string type) : _type(type)
{
	putMessage(YELLOW, "Name constructor of Animal is called", 1);
}

Animal::Animal(const Animal& copy)
{
	putMessage(YELLOW, "Copy constructor of Animal is called", 1);
	*this = copy;
}

Animal & Animal::operator=(const Animal& assign)
{
	this->_type = assign.getType();
	return (*this);
}

Animal::~Animal()
{
	putMessage(PURP, "Destructor of " , 0);
	putMessage(PURP, getType() , 0);
	putMessage(PURP, " is called" , 1);
}

// Member functions
void	Animal::makeSound() const
{
	putMessage(L_BLUE, "What does a JellyFish, Starfish, Worm or Snail say? Nothing :)", 1);
}

std::string	Animal::getType() const
{
	return (this->_type);
}
