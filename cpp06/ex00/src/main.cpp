/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/21 19:27:37 by itopchu       #+#    #+#                 */
/*   Updated: 2023/10/21 19:27:37 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char* av[])
{
	std::string test = "HELLO";
    if (ac == 1)
	{
        std::cerr << "Usage: <input_literal> <input_literal> ..." << std::endl;
        return 1;
    }
	for (int i = 1; i < ac; i++)
	{
		ScalarConverter::convert(av[i]);
	}
    return 0;
}