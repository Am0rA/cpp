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
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iomanip>

void	putMessage(const char* color, const std::string& message, int newline)
{
	std::cout << color << message << C_RESET;
	if (newline)
		std::cout << std::endl;
}

int main(void)
{
	{
		std::cout << C_GREEN << "----------------------[TEST1] : ShrubberyCreationForm----------------------" << C_RESET << std::endl;
		ShrubberyCreationForm shruberry1("test1");
		try {
			Bureaucrat coni("Coni", 10);
			std::cout << coni << std::endl;
			coni.signForm(shruberry1);
			std::cout << shruberry1 << std::endl;
			coni.executeForm(shruberry1);
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
		ShrubberyCreationForm shruberry2("test2");
		try {
			Bureaucrat coni("coni", 145);
			std::cout << coni << std::endl;
			coni.signForm(shruberry2);
			std::cout << shruberry2 << std::endl;
			coni.executeForm(shruberry2);
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
		ShrubberyCreationForm shruberry3("test3");
		try {
			Bureaucrat coni("Coni", 150);
			std::cout << coni << std::endl;
			coni.signForm(shruberry3);
			std::cout << shruberry3 << std::endl;
			coni.executeForm(shruberry3);
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << C_GREEN << "----------------------[TEST2] : RobotomyRequestForm----------------------" << C_RESET << std::endl;
		RobotomyRequestForm rf1("test1");
		try {
			Bureaucrat coni("Coni", 10);
			std::cout << coni << std::endl;
			coni.signForm(rf1);
			std::cout << rf1 << std::endl;
			coni.executeForm(rf1);
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
		RobotomyRequestForm robotomy("test2");
		try {
			Bureaucrat coni("coni", 50);
			std::cout << coni << std::endl;
			coni.signForm(robotomy);
			std::cout << robotomy << std::endl;
			coni.executeForm(robotomy);
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
		RobotomyRequestForm rf3("test3");
		try {
			Bureaucrat coni("Coni", 100);
			std::cout << coni << std::endl;
			coni.signForm(rf3);
			std::cout << rf3 << std::endl;
			coni.executeForm(rf3);
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << C_GREEN << "----------------------[TEST3] : PresidentialPardonForm----------------------" << C_RESET << std::endl;
		PresidentialPardonForm pf1("test1");
		try {
			Bureaucrat coni("Coni", 4);
			std::cout << coni << std::endl;
			coni.signForm(pf1);
			std::cout << pf1 << std::endl;
			coni.executeForm(pf1);
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
		PresidentialPardonForm pf2("test2");
		try {
			Bureaucrat coni("coni", 20);
			std::cout << coni << std::endl;
			coni.signForm(pf2);
			std::cout << pf2 << std::endl;
			coni.executeForm(pf2);
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
		PresidentialPardonForm pf3("test3");
		try {
			Bureaucrat coni("Coni", 100);
			std::cout << coni << std::endl;
			coni.signForm(pf3);
			std::cout << pf3 << std::endl;
			coni.executeForm(pf3);
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
}