/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/24 04:07:43 by itopchu       #+#    #+#                 */
/*   Updated: 2023/10/24 04:07:43 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
	int inters[] = {1, 2, 3, 4, 5};
	std::string stringers[] = {"Sometimes", " ", "it", " ", "is", " ", "just", " ", "too", " ", "much", "."};

	size_t	s_int = sizeof(inters) / sizeof(inters[0]);
	size_t s_str = sizeof(stringers) / sizeof(stringers[0]);

	std::cout << "int array: ";
	::iter(inters, s_int, printElement);
	std::cout << std::endl;

	std::cout << "string array: ";
	::iter(stringers, s_str, printElement);
	std::cout << std::endl;
}