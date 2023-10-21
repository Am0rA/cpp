/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/18 19:41:00 by itopchu       #+#    #+#                 */
/*   Updated: 2023/10/18 19:41:00 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) :
	__name("Default"),
	__target("Default"),
	__recuiredGrade(42),
	__executeGrade(42),
	__sign(false)
{
	putMessage(C_YELLOW, "Default constructor of AForm is called", 1);
}

AForm::~AForm(void)
{
	putMessage(C_PURPLE, "Destructor of AForm is called", 1);
}

AForm::AForm(const AForm& copy) :
	__name(copy.getName()),
	__target(copy.getTarget()),
	__recuiredGrade(copy.getRecuired()),
	__executeGrade(copy.getExecute()),
	__sign(copy.getSign())
{
	putMessage(C_YELLOW, "Copy constructor of AForm is called", 1);
}

AForm& AForm::operator=(const AForm& assign)
{
	const_cast<std::string &>(__name) = assign.getName();
	const_cast<std::string &>(__target) = assign.getTarget();
	const_cast<int &>(__executeGrade) = assign.getExecute();
	const_cast<int &>(__recuiredGrade) = assign.getRecuired();
	this->__sign = assign.getSign();
	return (*this);
}

AForm::AForm(std::string const & name, std::string const & target,int recuiredGrade, int executeGrade) :
	__name(name),
	__target(target),
	__recuiredGrade(recuiredGrade),
	__executeGrade(executeGrade),
	__sign(false)
{
	putMessage(C_YELLOW, "Name constructor of AForm is called", 1);
	if (recuiredGrade < 1 || executeGrade < 1)
		throw (GradeTooHighException());
	if (recuiredGrade > 150 || executeGrade > 150)
		throw (GradeTooLowException());
}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > getRecuired())
		throw (GradeTooLowException());
	this->__sign = true;
}

void	AForm::setSign(bool condition)
{
	this->__sign = condition;
}

std::string const & AForm::getName(void) const
{
	return (this->__name);
}

std::string const & AForm::getTarget(void) const
{
	return (this->__target);
}

bool const &	AForm::getSign(void) const
{
	return (this->__sign);
}

int const &		AForm::getRecuired(void) const
{
	return (this->__recuiredGrade);
}

int const &		AForm::getExecute(void) const
{
	return (this->__executeGrade);
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("Grades can't be lower than 150.");
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("Grades can't be higher than 1.");
}

const char* AForm::NotSignedException::what() const throw()
{

	return "Unable to execute unsigned form.";
}


std::ostream & operator<<(std::ostream &o, AForm const &obj)
{
	o << "AForm name: " C_BLUE << obj.getName() << C_RESET << std::endl \
	<< "Is signed: "; 
	obj.getSign() ? o << C_GREEN "True" C_RESET : o << C_RED "False" C_RESET;
	o << std::endl << "Grade to sign: " C_BLUE << obj.getRecuired() << std::endl \
	<< C_RESET "Grade to execute: " C_BLUE << obj.getExecute() << C_RESET;
	return o;
}