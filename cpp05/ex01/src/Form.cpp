/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/15 17:13:16 by itopchu       #+#    #+#                 */
/*   Updated: 2023/10/15 17:13:16 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) :
	mc__name("DEFAULT"),
	mc__recuiredGrade(150),
	mc__executeGrade(150),
	m__sign(false)
{
	putMessage(YELLOW, "Default constructor of Form is called", 1);
}

Form::~Form(void)
{
	putMessage(PURP, "Default destructor of Form is called", 1);
}

Form::Form(Form const & copy) :
	mc__name(copy.getName()),
	mc__recuiredGrade(copy.getRecuired()),
	mc__executeGrade(copy.getExecute())
{
	putMessage(YELLOW, "Copy constructor of Form is called", 1);
	this->m__sign = copy.getSign();
	*this = copy;
}

Form& Form::operator=(Form const & assign)
{
	std::cout << RED "Only non-const values assigned" DEFCOLOR << std::endl;
	this->m__sign = assign.m__sign;
	return (*this);
}

Form::Form(std::string const &name, int recuired, int execute) :
	mc__name(name),
	mc__recuiredGrade(recuired),
	mc__executeGrade(execute)
{
	putMessage(YELLOW, "Name constructor of Form is called", 1);
	if (recuired < 1 || execute < 1)
		throw(GradeTooHighException());
	else if (recuired > 150 || execute > 150)
		throw(GradeTooLowException());
	m__sign = false;
}

std::string const	&Form::getName(void) const
{
	return (mc__name);
}

bool const	&Form::getSign(void) const
{
	return (m__sign);
}

int const	&Form::getRecuired(void) const
{
	return (mc__recuiredGrade);
}

int const	&Form::getExecute(void) const
{
	return (mc__executeGrade);
}

void	Form::beSigned(const int &ref)
{
	if (ref >= this->mc__recuiredGrade)
		GradeTooLowException();
	this->m__sign = true;
}

std::ostream &operator<<(std::ostream &outs, Form const &form)
{
    outs << "Form: " << form.getName() << ", Grade required to sign: " << form.getRecuired()
       << ", Grade required to execute: " << form.getExecute() << ", Signed: ";
    if (form.getSign())
        outs << "Yes";
    else
        outs << "No";
    return outs;
}
