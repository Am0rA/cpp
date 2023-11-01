/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/25 04:02:41 by itopchu       #+#    #+#                 */
/*   Updated: 2023/10/25 04:02:41 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "Array.hpp"

#define EXTERN_VAL 259
int main(void)
{
	Array<int> pool(EXTERN_VAL);
	int*	mirror = new int[EXTERN_VAL];
	srand(time(NULL));
	for (int i = 0; i < EXTERN_VAL; i++)
	{
		const int value = rand();
		pool[i] = value;
		mirror[i] = value;
	}
	{
		Array<int> scope = pool;
		Array<int> copy(scope);
		std::cout << "copy[1]: " << copy[1] << std::endl;
		copy[1] = 42;
		std::cout << "copy[1]: " << copy[1] << std::endl;
		std::cout << "scope[1]: " << scope[1] << std::endl;
		copy[1] += 42;
		std::cout << "copy[1]: " << copy[1] << std::endl;
		std::cout << "scope[1]: " << scope[1] << std::endl;
	}
	try
	{
		std::cout << "---Out of range---" << std::endl;
		pool[EXTERN_VAL + 1] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception : " << e.what() << '\n';
	}
	delete[] mirror;
	return (0);
}
