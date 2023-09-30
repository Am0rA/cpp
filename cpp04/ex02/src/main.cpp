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

int main()
{
	std::cout << "--------------- Animal ---------------" << std::endl;

	//const Animal* meta = new Animal(); //Shouldn't compile
	// std::cout << "j : " RED "(" << j->getType() << ")" DEFCOLOR << " ";
	// meta->makeSound();
    const Animal* i = new Cat();
    const Animal* j = new Dog();
	std::cout << "i : " RED "(" << i->getType() << ")" DEFCOLOR << " ";
	i->makeSound();
	std::cout << "j : " RED "(" << j->getType() << ")" DEFCOLOR << " ";
	j->makeSound();
}