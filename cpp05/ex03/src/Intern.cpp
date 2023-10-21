/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/21 18:16:59 by itopchu       #+#    #+#                 */
/*   Updated: 2023/10/21 18:16:59 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <map>

Intern::Intern(void)
{

}

Intern::~Intern(void)
{

}

Intern::Intern(Intern const & intern)
{
	*this = intern;
}

Intern& Intern::operator=(Intern const & intern)
{
	(void)intern;
	return (*this);
}

const char *Intern::FormDoesNotExistException::what( void ) const throw() 
{
    return "FormDoesNotExist";
}

AForm* createShrubberyCreationForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* createRobotomyRequestForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* createPresidentialPardonForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}

AForm*	Intern::makeForm(std::string const & name, std::string const & target)
{
	std::string forms[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	try
	{
		int i;
		for (i = 0; i < 3 && forms[i] != name; i++);
		if (i != 3)
			std::cout << "Intern creates " C_GREEN << name << C_RESET << std::endl;
		switch (i)
		{
			case 0 : return new ShrubberyCreationForm(target);
			case 1 : return new RobotomyRequestForm(target);
			case 2 : return new PresidentialPardonForm(target);
		}
		throw FormDoesNotExistException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (NULL);
}