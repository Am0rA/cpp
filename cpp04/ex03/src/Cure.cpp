/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cure.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 00:03:20 by itopchu       #+#    #+#                 */
/*   Updated: 2023/10/02 00:03:20 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure(void) :
	AMateria("cure")
{
	putMessage(YELLOW, "Default Constructor of Cure is called", 1);
}

Cure::~Cure(void)
{
	putMessage(PURP, "Default Destructor of Cure is called", 1);
}

Cure::Cure(Cure const & copy) :
	AMateria(copy)
{
	putMessage(YELLOW, "Copy Constructor of Cure is called", 1);
}

Cure& Cure::operator=(Cure const & assign)
{
	if (this != &assign)
		m_type = assign.m_type;
	return (*this);
}

AMateria*	Cure::clone(void) const
{
	return (new Cure(*this));
}

void	Cure::use(ICharacter& target)
{
	putMessage(BLUE, "* heals ", 0);
	putMessage(GREEN, target.getName(), 0);
	putMessage(BLUE, "’s wounds *", 1);
}
