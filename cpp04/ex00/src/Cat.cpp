/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/20 21:47:26 by itopchu       #+#    #+#                 */
/*   Updated: 2023/09/20 21:47:26 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() :
	Animal("Cat")
{
	putMessage(YELLOW, "Default constructor of Cat is called", 1);
}

Cat::Cat(const Cat &assign)
{
	putMessage(YELLOW, "A copy of ", 0);
	putMessage(YELLOW, this->getType(), 0);
	putMessage(YELLOW, " is created", 1);
	*this = assign;
}

Cat & Cat::operator=(const Cat &assign)
{
	this->_type = assign.getType();
	return *this;
}

Cat::~Cat()
{
	putMessage(PURP, "Default destructor of Cat is called", 1);
}

void	Cat::makeSound() const
{
	putMessage(L_BLUE, "I say Miyav not Meow!", 1);
}
