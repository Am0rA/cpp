/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.cpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/19 17:29:17 by itopchu       #+#    #+#                 */
/*   Updated: 2023/10/19 17:29:17 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
	AForm(NULL, NULL, 25, 5)
{

}

PresidentialPardonForm::PresidentialPardonForm(std::string const & target) :
	AForm("PresidentialPardonForm", target, 25, 5)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) :
	AForm(copy.getName(), copy.getTarget(), 25, 5)
{
	*this = copy;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{

}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& assign) 
{
	setSign(assign.getSign());
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const 
{
	if (!this->getSign())
		throw(NotSignedException());
	if (executor.getGrade() > this->getExecute())
		throw(GradeTooLowException());
	std::cout << C_BLUE << this->getTarget() << C_RESET << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	return;
}
