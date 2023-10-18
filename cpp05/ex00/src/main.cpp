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
	std::cout << color << message << C_RESET;
	if (newline)
		std::cout << std::endl;
}

int	main(void)
{
	{
		try
		{
			putMessage(C_CYAN, "[TEST 1] : Valid increment", 1);
			Bureaucrat coni("Coni", 2);
			std::cout << coni << std::endl;
			coni.increaseGrade();
			std::cout << coni << std::endl;
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		try
		{
			putMessage(C_CYAN, "[TEST 2] : Valid decrement", 1);
			Bureaucrat coni("Coni", 149);
			std::cout << coni << std::endl;
			coni.decreaseGrade();
			std::cout << coni << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}		
	}
	std::cout << std::endl;
	{
		try
		{
			putMessage(C_CYAN, "[TEST 3] : Invalid increment", 1);
			Bureaucrat coni("Coni", 1);
			std::cout << coni << std::endl;
			coni.increaseGrade();
			std::cout << coni << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}		
	}
	std::cout << std::endl;
	{
		try
		{
			putMessage(C_CYAN, "[TEST 4] : Invalid decrement", 1);
			Bureaucrat coni("Coni", 150);
			std::cout << coni << std::endl;
			coni.decreaseGrade();
			std::cout << coni << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}		
	}
	std::cout << std::endl;
	{
		try
		{
			putMessage(C_CYAN, "[TEST 5] : Construct too high", 1);
			Bureaucrat coni("Coni", 0);
			std::cout << coni << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}		
	}
	std::cout << std::endl;
	{
		try
		{
			putMessage(C_CYAN, "[TEST 6] : Construct too low", 1);
			Bureaucrat coni("Coni", 151);
			std::cout << coni << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}		
	}
	std::cout << std::endl;
	{
		try
		{
			putMessage(C_CYAN, "[TEST 7] : Construct copy", 1);
			Bureaucrat coni("Coni", 42);
			Bureaucrat murphy("Murphy", 11);
			coni = murphy;
			std::cout << coni << std::endl << murphy << std::endl;
			Bureaucrat	kop(coni);
			std::cout << kop << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}		
	}
	return (0);
}
