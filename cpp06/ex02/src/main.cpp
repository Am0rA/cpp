/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/23 17:33:56 by itopchu       #+#    #+#                 */
/*   Updated: 2023/10/23 17:33:56 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base * generate(void)
{
	std::srand(std::time(NULL));
	int	rand = std::rand() % 3;
	switch (rand)
	{
		case 0: return new A();
		case 1: return new B();
		case 2: return new C();
		default: return  NULL;
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else 
		std::cout << "none" << std::endl;
}

void identify(Base& p)
{
	try {
		void(dynamic_cast<A&>(p));
		std::cout << "A" << std::endl;
		return ;
	}
	catch (std::exception&) {}
	try {
		void(dynamic_cast<B&>(p));
		std::cout << "B" << std::endl;
		return ;
	}
	catch (std::exception&) {}
	try {
		void(dynamic_cast<C&>(p));
		std::cout << "C" << std::endl;
		return ;
	}
	catch (std::exception&) {}
	std::cout << "none" << std::endl;
}

int main(void)
{
	Base*	foo = generate();

	identify(foo);
	identify(*foo);

	delete foo;
	return 0;
}
