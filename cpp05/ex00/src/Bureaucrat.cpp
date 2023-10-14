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

int Bureaucrat::ms__amount = 1;
void	putMessage(const char* color, const std::string& message, int newline);

Bureaucrat::Bureaucrat(void) :
	m__name("DEFAULT:" + ms__amount),
	m__grade(ms__amount % 151)
{
	ms__amount++;
	putMessage(YELLOW, "Default constructor of Bureaucrat is called", 1);
}
Bureaucrat::~Bureaucrat(void)
{
	putMessage(YELLOW, "Default destructor of Bureaucrat is called", 1);
}
Bureaucrat::Bureaucrat(Bureaucrat const & copy)
{
	putMessage(YELLOW, "Copy constructor of Bureaucrat is called", 1);
	*this = copy;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const & assign)
{
	this->m__grade = assign.getGrade();
	this->m__name = assign.getName();
	// this->ms__amount = assign.ms__amount;
	return *this;
}

Bureaucrat::Bureaucrat(std::string const &name, int const &grade) :
	m__name(name),
	m__grade(grade)
{
	if (m__grade < 1)
		throw GradeTooHighException(m__grade);
	if (m__grade > 150)
		throw GradeTooLowException(m__grade);
	putMessage(YELLOW, "Name constructor of Bureaucrat is called", 1);
	ms__amount++;
}

std::string const & Bureaucrat::getName(void) const
{
	return(this->m__name);
}

int const & Bureaucrat::getGrade(void) const
{
	return (this->m__grade);
}

std::ostream &operator<<(std::ostream &outs, Bureaucrat const &bureau)
{
	outs << "Name: " BLUE << bureau.getName() << DEFCOLOR ", Grade: " GREEN << bureau.getGrade() << DEFCOLOR;
    return outs;
}

void	Bureaucrat::increaseGrade(int amount)
{
	if (this->m__grade - amount < 1)
		throw GradeTooHighException(amount);
	m__grade -= amount;
}

void	Bureaucrat::decreaseGrade(int amount)
{
	if (this->m__grade + amount > 150)
		throw GradeTooLowException(amount);
	m__grade += amount;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(int amount)
{
	std::stringstream converter;
	converter << amount;
	message = "You can't increase with " + converter.str();
}

Bureaucrat::GradeTooLowException::GradeTooLowException(int amount)
{
	std::stringstream converter;
	converter << amount;
	message = "You can't decrease with " + converter.str();
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{

}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{

}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return message.c_str();
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return message.c_str();
}