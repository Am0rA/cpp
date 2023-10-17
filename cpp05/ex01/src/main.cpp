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

#include "Form.hpp"

void	putMessage(const char* color, const std::string& message, int newline)
{
	std::cout << color << message << DEFCOLOR;
	if (newline)
		std::cout << std::endl;
}

int	main(void)
{
    try {
        Bureaucrat bureaucrat1("John", 10);
        Bureaucrat bureaucrat2("Alice", 100);

        Form form1("Tax Return", 20, 30);
        Form form2("License Renewal", 5, 15);

        std::cout << bureaucrat1 << std::endl;
        std::cout << bureaucrat2 << std::endl;
        std::cout << form1 << std::endl;
        std::cout << form2 << std::endl;

        bureaucrat1.signForm(form1);
        bureaucrat2.signForm(form2);
    } catch (Form::GradeTooHighException &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (Form::GradeTooLowException &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
