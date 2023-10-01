/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MateriaSource.cpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 00:29:16 by itopchu       #+#    #+#                 */
/*   Updated: 2023/10/02 00:29:16 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	putMessage(YELLOW, "Default Constructor of MateriaSource is called", 1);
	for (int i = 0; i < 4; i++)
		mp__materias[i] = NULL;
}

MateriaSource::~MateriaSource(void)
{
	putMessage(PURP, "Default Destructor of MateriaSource is called", 1);
	for (int i = 0; i < 4; i++)
		delete mp__materias[i];
}

MateriaSource::MateriaSource(MateriaSource const & copy)
{
	putMessage(YELLOW, "Copy Constructor of MateriaSource is called", 1);
    for(int i = 0; i < 4; ++i)
	{
		delete mp__materias[i];
		mp__materias[i] = NULL;
		if (copy.mp__materias[i])
			mp__materias[i] = copy.mp__materias[i]->clone();

	}
}

MateriaSource& MateriaSource::operator=(MateriaSource const & assign)
{
        if(this != &assign)
		{
            for(int i = 0; i < 4; ++i)
			{
                delete mp__materias[i];
				mp__materias[i] = NULL;
				if (assign.mp__materias[i])
					mp__materias[i] = assign.mp__materias[i];
            }
        }
        return *this;
}

void	MateriaSource::learnMateria(AMateria* m)
{
	int	i = 0;
	while (i < 4 && mp__materias[i])
		i++;
	if (i < 4)
		mp__materias[i] = m;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	int i = 0;
	while (i < 4 && (!mp__materias[i] || mp__materias[i]->getType() != type))
		i++;
	if (i < 4)
		return mp__materias[i]->clone();
	return (NULL);
}
