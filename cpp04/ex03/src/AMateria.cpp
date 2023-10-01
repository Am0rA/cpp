/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AMateria.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/01 22:28:52 by itopchu       #+#    #+#                 */
/*   Updated: 2023/10/01 22:28:52 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) :
	m_type("NULL")
{
	putMessage(YELLOW, "Default Constructor of AMateria is called", 1);
}

AMateria::~AMateria(void)
{
	putMessage(PURP, "Default Destructor of AMateria is called", 1);
}

AMateria::AMateria(AMateria const & copy) :
	m_type(copy.m_type)
{
	putMessage(YELLOW, "Copy Constructor of AMateria is called", 1);
}

AMateria & AMateria::operator=(AMateria const & assign)
{
	if (this != &assign)
		m_type = assign.m_type;
	return (*this);
}

AMateria::AMateria(std::string const & type) :
	m_type(type)
{
	putMessage(YELLOW, "Name Constructor of AMateria is called", 1);
}

std::string const & AMateria::getType(void) const
{
	return (m_type);
}

void	AMateria::use(ICharacter& target)
{
	(void)target;
}
