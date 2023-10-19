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
#include "Form.hpp"

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
			putMessage(C_CYAN, "[TEST 1] : Valid higher sign", 1);
			Bureaucrat coni("Coni", 2);
			Form lesh("lesh", 42, 120);
			std::cout << coni << std::endl;
			std::cout << lesh << std::endl;
			lesh.beSigned(coni);
			std::cout << lesh << std::endl;
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
			putMessage(C_CYAN, "[TEST 2] : Valid equal sign", 1);
			Bureaucrat coni("Coni", 2);
			Form lesh("lesh", 2, 120);
			std::cout << coni << std::endl;
			std::cout << lesh << std::endl;
			lesh.beSigned(coni);
			std::cout << lesh << std::endl;
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
			putMessage(C_CYAN, "[TEST 3] : Invalid lowergrade", 1);
			Bureaucrat coni("Coni", 11);
			Form lesh("Lesh", 10, 120);
			std::cout << coni << std::endl;
			std::cout << lesh << std::endl;
			coni.signForm(lesh);
			std::cout << lesh << std::endl;
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
			putMessage(C_CYAN, "[TEST 4] : Invalid higher", 1);
			Bureaucrat coni("Coni", 11);
			Form lesh("Lesh", 12, 12);
			std::cout << coni << std::endl;
			std::cout << lesh << std::endl;
			coni.signForm(lesh);
			std::cout << lesh << std::endl;
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
			putMessage(C_CYAN, "[TEST 5] : Invalid Construct", 1);
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
			putMessage(C_CYAN, "[TEST 6] : Invalid Construct", 1);
			Form lesh("Lesh", 0, 0);
			std::cout << lesh << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}		
	}
	return (0);
}
