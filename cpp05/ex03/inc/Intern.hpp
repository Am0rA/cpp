/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/21 18:17:02 by itopchu       #+#    #+#                 */
/*   Updated: 2023/10/21 18:17:02 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
class Intern
{
	public:
		// Form
		Intern(void);
		virtual ~Intern();
		Intern(Intern const & src);
		Intern& operator=(Intern const & assign);
		// Subject
		AForm*	makeForm(std::string const & name, std::string const & target);
		class FormDoesNotExistException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

#endif