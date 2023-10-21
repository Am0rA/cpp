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
#include "Intern.hpp"
#include <iomanip>

void	putMessage(const char* color, const std::string& message, int newline)
{
	std::cout << color << message << C_RESET;
	if (newline)
		std::cout << std::endl;
}

int main(void)
{
	Intern intern;
	AForm *form;

	std::cout << C_GREEN << "[TEST 1]"  << C_RESET " : Shrubbery " << std::endl;
	form = intern.makeForm("ShrubberyCreationForm", "target1");
	delete form;
	std::cout << C_GREEN << "[TEST 2]"  << C_RESET " : Robotomy " << std::endl;
	form = intern.makeForm("RobotomyRequestForm", "target2");
	delete form;
	std::cout << C_GREEN << "[TEST 3]"  << C_RESET " : Presidential " << std::endl;
	form = intern.makeForm("PresidentialPardonForm", "target3");
	delete form;
	std::cout << C_GREEN << "[TEST 4]"  << C_RESET " : wrongForm " << std::endl;
	form = intern.makeForm("wrongForm", "target4");
	delete form;
}