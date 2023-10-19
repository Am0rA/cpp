/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/13 02:27:02 by itopchu       #+#    #+#                 */
/*   Updated: 2023/10/13 02:27:02 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	putMessage(const char* color, const std::string& message, int newline);

Bureaucrat::Bureaucrat(void) :
	__name("DEFAULT"),
	__grade(42)
{
	putMessage(C_YELLOW, "Default constructor of Bureaucrat is called", 1);
}

Bureaucrat::~Bureaucrat(void)
{
	putMessage(C_PURPLE, "Destructor of Bureaucrat is called", 1);
}

Bureaucrat::Bureaucrat(Bureaucrat const & copy) :
	__name(copy.getName()),
	__grade(copy.getGrade())
{
	putMessage(C_YELLOW, "Copy constructor of Bureaucrat is called", 1);
	*this = copy;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const & assign)
{
	putMessage(C_YELLOW, "Copy assignment operator of Bureaucrat is called", 1);
	this->__grade = assign.getGrade();
	const_cast<std::string &>(__name) = assign.getName();
	return *this;
}

Bureaucrat::Bureaucrat(std::string const &name, int const &grade) :
	__name(name),
	__grade(grade)
{
	putMessage(C_YELLOW, "Name constructor of Bureaucrat is called", 1);
	if (__grade < 1)
		throw GradeTooHighException();
	if (__grade > 150)
		throw GradeTooLowException();
}

std::string const & Bureaucrat::getName(void) const
{
	return(this->__name);
}

int const & Bureaucrat::getGrade(void) const
{
	return (this->__grade);
}

void	Bureaucrat::increaseGrade()
{
	if (this->__grade == 1)
		throw (GradeTooHighException());
	this->__grade--;
	std::cout << "Bureaucrat grade increased to " C_BLUE << getGrade() << std::endl;
}

void	Bureaucrat::decreaseGrade()
{
	if (this->__grade == 150)
		throw (GradeTooLowException());
	__grade++;
	std::cout << "Bureaucrat grade decreased to " C_RED << getGrade() << std::endl;
}

void	Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << C_BLUE << __name << C_GREEN " signed " C_CYAN << form.getName() << C_RESET << std::endl;
	}
	catch(const std::exception& e)
	{
        std::cout << C_BLUE << __name << C_RED " couldn't sign " C_CYAN << form.getName() << C_RESET " because " << e.what() << std::endl;
	}
	
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grades can't be higher than 1.";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grades can't be lower than 150.";
}

std::ostream &operator<<(std::ostream &outs, Bureaucrat const &bureau)
{
	outs << "Name: " C_BLUE << bureau.getName() << C_RESET \
	", Grade: " C_GREEN << bureau.getGrade() << C_RESET;
    return outs;
}
