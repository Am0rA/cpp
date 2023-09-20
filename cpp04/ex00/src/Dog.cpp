/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/20 21:50:59 by itopchu       #+#    #+#                 */
/*   Updated: 2023/09/20 21:50:59 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() :
	Animal("Dog")
{
	putMessage(YELLOW, "Default constructor of Dog is called", 1);
}

Dog::~Dog()
{
	putMessage(PURP, "Default destructor of Dog is called", 1);
}

void	Dog::makeSound() const
{
	putMessage(L_BLUE, "I say Hav not Woof!", 1);
}
