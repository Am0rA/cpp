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

#include "Bureaucrat.hpp"

void	putMessage(const char* color, const std::string& message, int newline)
{
	std::cout << color << message << DEFCOLOR;
	if (newline)
		std::cout << std::endl;
}

int	main(void)
{
	try
	{
		Bureaucrat choko("Choko", 30);
		std::cout << choko << std::endl;
		choko.decreaseGrade(30);
		std::cout << choko << std::endl;
		// choko.decreaseGrade(100);
		// std::cout << choko << std::endl;
		choko.increaseGrade(50);
		std::cout << choko << std::endl;
		choko.increaseGrade(10);
		std::cout << choko << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
