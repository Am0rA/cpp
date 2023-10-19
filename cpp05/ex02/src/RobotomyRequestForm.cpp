/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.cpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/19 17:23:46 by itopchu       #+#    #+#                 */
/*   Updated: 2023/10/19 17:23:46 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <ctime>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() :
	AForm(NULL, NULL, 72, 45)
{

}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target) :
	AForm("RobotomyRequestForm", target, 72, 45)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) :
	AForm(copy.getName(), copy.getTarget(), 72, 45)
{
	*this = copy;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{

}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& assign) 
{
	setSign(assign.getSign());
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const 
{
	if (!this->getSign())
		throw(NotSignedException());
	if (executor.getGrade() > this->getExecute())
		throw(GradeTooLowException());
    const char* message = "czjtzjdstsj";
	std::cout << C_BLUE;
	while (*message)
	{
		std::cout << *message << std::flush;
        std::clock_t start_time = std::clock();
		while ((std::clock() - start_time) < (0.2 * CLOCKS_PER_SEC))
			;
		message++;
	}
    std::cout << C_RESET << std::endl;
	std::srand(time(NULL));
	int random = rand() % 2;
	if (random == 0) {
		std::cout << this->getTarget() << " has been robotomized successfully!" << std::endl;
	}
	else
		std::cout << "Robotomy failed..." << std::endl;
    std::clock_t start_time = std::clock();
	while ((std::clock() - start_time) < (2 * CLOCKS_PER_SEC))
		;
}
