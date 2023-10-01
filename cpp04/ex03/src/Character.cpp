/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Character.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 00:06:50 by itopchu       #+#    #+#                 */
/*   Updated: 2023/10/02 00:06:50 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void) :
	m__name("NULL")
{
	putMessage(YELLOW, "Default Constructor of Character is called", 1);
	for (int i = 0; i < 4; i++)
		mp__inventory[i] = NULL;
}

Character::Character(std::string const & name) :
	m__name(name)
{
	putMessage(YELLOW, "Name Constructor of Character is called", 1);
	for (int i = 0; i < 4; i++)
		mp__inventory[i] = NULL;
}

Character::~Character(void)
{
	putMessage(PURP, "Default Destructor of Character is called", 1);
	for (int i = 0; i < 4; i++)
		delete mp__inventory[i];
}

Character::Character(Character const & copy) :
	m__name(copy.m__name)
{
	putMessage(YELLOW, "Copy Constructor of Character is called", 1);
    for(int i = 0; i < 4; ++i)
	{
		mp__inventory[i] = NULL;
		if (copy.mp__inventory[i])
			mp__inventory[i] = copy.mp__inventory[i]->clone();

	}
}

Character& Character::operator=(Character const & assign)
{
        if(this != &assign) {
            m__name = assign.m__name;
            for(int i = 0; i < 4; ++i)
			{
                delete mp__inventory[i];
				mp__inventory[i] = NULL;
				if (assign.mp__inventory[i])
					mp__inventory[i] = assign.mp__inventory[i];
            }
        }
        return *this;
}

void	Character::equip(AMateria* m)
{
	int i = 0;
	while (i < 4 && mp__inventory[i])
		i++;
	if (i < 4)
		mp__inventory[i] = m;
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
		mp__inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && mp__inventory[idx])
		mp__inventory[idx]->use(target);
}

std::string const & Character::getName(void) const
{
	return (m__name);
}
