/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/27 11:03:29 by itopchu       #+#    #+#                 */
/*   Updated: 2023/09/27 11:03:29 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

void	putMessage(const char* color, const std::string& message, int newline)
{
	std::cout << color << message << DEFCOLOR;
	if (newline)
		std::cout << std::endl;
}

int main(void)
{
	IMateriaSource* bucket = new MateriaSource();
	bucket->learnMateria(new Ice());
	bucket->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");

	// Test: Equip and use "ice" materia
	me->equip(bucket->createMateria("ice"));
	// Expected: * shoots an ice bolt at bob *
	me->use(0, *bob);
	// Test: Equip and use "cure" materia
	me->equip(bucket->createMateria("cure"));
	// Expected: * heals bob’s wounds *
	me->use(1, *bob);
	// Test: Use an unequipped materia (index 2 is not equipped)
	// Expected: No output
	me->use(2, *bob);
	// Test: Unequip "ice" materia and try to use it
	me->unequip(0);
	// Expected: No output
	me->use(0, *bob);
	// Test: Try to equip more materias than the inventory can hold
	for(int i = 0; i < 5; ++i)
		me->equip(bucket->createMateria("ice"));
	// Expected: * shoots an ice bolt at bob *
	me->use(3, *bob);
	// Expected: No output
	me->use(4, *bob);
	// Test: Deep copy of a character and use its materia
	ICharacter* meClone = new Character(*static_cast<Character*>(me));
	// Expected: * heals bob’s wounds *
	meClone->use(1, *bob);
	// Cleanup
	delete bob, delete me, delete meClone, delete bucket;
	return (0);
}
