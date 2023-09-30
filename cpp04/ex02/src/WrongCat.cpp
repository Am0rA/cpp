/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongCat.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/20 22:16:03 by itopchu       #+#    #+#                 */
/*   Updated: 2023/09/20 22:16:03 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() :
	WrongAnimal("WrongCat")
{
	putMessage(YELLOW, "Default constructor of WrongCat is called", 1);
}

WrongCat::~WrongCat()
{
	putMessage(PURP, "Default destructor of WrongCat is called", 1);
}

void WrongCat::makeSound() const
{
	putMessage(L_BLUE, "I say Mihhryav not Meow!", 1);
}
