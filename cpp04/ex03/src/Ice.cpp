/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Ice.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/01 22:38:54 by itopchu       #+#    #+#                 */
/*   Updated: 2023/10/01 22:38:54 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice(void) :
	AMateria("ice")
{
	putMessage(YELLOW, "Default Constructor of Ice is called", 1);
}

Ice::~Ice(void)
{
	putMessage(PURP, "Default Destructor of Ice is called", 1);
}

Ice::Ice(Ice const & copy) :
	AMateria(copy)
{
	putMessage(YELLOW, "Copy Constructor of Ice is called", 1);
}

Ice& Ice::operator=(Ice const & assign)
{
	if (this != &assign)
		m_type = assign.m_type;
	return (*this);
}

AMateria*	Ice::clone(void) const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter& target)
{
	putMessage(BLUE, "* shoots an ice bolt at ", 0);
	putMessage(RED, target.getName(), 0);
	putMessage(BLUE, " *", 1);
}
