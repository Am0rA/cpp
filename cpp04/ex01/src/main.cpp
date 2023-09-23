/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/20 18:08:51 by itopchu       #+#    #+#                 */
/*   Updated: 2023/09/20 18:08:51 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void	putMessage(const char* color, const std::string& message, int newline)
{
	std::cout << color << message << DEFCOLOR;
	if (newline)
		std::cout << std::endl;
}

int	main(void)
{
	const Animal*	meta = new Animal();
	const Animal*	dog = new Dog();
	const Animal*	cat = new Cat();

	putMessage(BLUE, meta->getType(), 1);
	putMessage(BLUE, dog->getType(), 1);
	putMessage(BLUE, cat->getType(), 1);
	meta->makeSound();
	cat->makeSound();
	dog->makeSound();
	delete meta, delete dog, delete cat;
	putMessage(RED, "------------Wrong part------------", 1);
	const WrongAnimal*	wrongAnimal = new WrongAnimal();
	const WrongAnimal*	wrongCat = new WrongCat();
	putMessage(BLUE, wrongAnimal->getType(), 1);
	putMessage(BLUE, wrongCat->getType(), 1);
	wrongCat->makeSound();
	wrongAnimal->makeSound();

	delete wrongCat, delete wrongAnimal;
	return (0);
}
