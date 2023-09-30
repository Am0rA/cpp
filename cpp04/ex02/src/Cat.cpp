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
	this->brain = new Brain();
	putMessage(YELLOW, "Default constructor of Cat is called", 1);
}

Cat::Cat(const Cat &assign) :
	Animal(assign.getType())
{
	if (this != &assign)
	{
		delete this->brain;
		this->brain = new Brain();
		for (int i = 0; i < 100; i++)
			this->brain->ideas[i] = assign.brain->ideas[i];
	}
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
	delete brain;
	putMessage(PURP, "Default destructor of Cat is called", 1);
}

void	Cat::makeSound() const
{
	putMessage(L_BLUE, "I say Miyav not Meow!", 1);
}
