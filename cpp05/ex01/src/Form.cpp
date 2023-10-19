/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/18 19:41:00 by itopchu       #+#    #+#                 */
/*   Updated: 2023/10/18 19:41:00 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) :
	__name("Default"),
	__recuiredGrade(42),
	__executeGrade(42),
	__sign(false)
{
	putMessage(C_YELLOW, "Default constructor of Form is called", 1);
}

Form::~Form(void)
{
	putMessage(C_PURPLE, "Destructor of Form is called", 1);
}

Form::Form(const Form& copy) :
	__name(copy.getName()),
	__recuiredGrade(copy.getRecuired()),
	__executeGrade(copy.getExecute()),
	__sign(copy.getSign())
{
	putMessage(C_YELLOW, "Copy constructor of Form is called", 1);
}

Form& Form::operator=(const Form& assign)
{
	const_cast<std::string &>(__name) = assign.getName();
	const_cast<int &>(__executeGrade) = assign.getExecute();
	const_cast<int &>(__recuiredGrade) = assign.getRecuired();
	this->__sign = assign.getSign();
	return (*this);
}

Form::Form(std::string const & name, int recuiredGrade, int executeGrade) :
	__name(name),
	__recuiredGrade(recuiredGrade),
	__executeGrade(executeGrade),
	__sign(false)
{
	putMessage(C_YELLOW, "Name constructor of Form is called", 1);
	if (recuiredGrade < 1 || executeGrade < 1)
		throw (GradeTooHighException());
	if (recuiredGrade > 150 || executeGrade > 150)
		throw (GradeTooLowException());
}

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > getRecuired())
		throw (GradeTooLowException());
	this->__sign = true;
}

std::string const & Form::getName(void) const
{
	return (this->__name);
}

bool const &	Form::getSign(void) const
{
	return (this->__sign);
}

int const &		Form::getRecuired(void) const
{
	return (this->__recuiredGrade);
}

int const &		Form::getExecute(void) const
{
	return (this->__executeGrade);
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("Grades can't be lower than 150.");
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Grades can't be higher than 1.");
}

std::ostream & operator<<(std::ostream &o, Form const &obj)
{
	o << "Form name: " C_BLUE << obj.getName() << C_RESET << std::endl \
	<< "Is signed: "; 
	obj.getSign() ? o << C_GREEN "True" C_RESET : o << C_RED "False" C_RESET;
	o << std::endl << "Grade to sign: " C_BLUE << obj.getRecuired() << std::endl \
	<< C_RESET "Grade to execute: " C_BLUE << obj.getExecute() << C_RESET << std::endl;
	return o;
}