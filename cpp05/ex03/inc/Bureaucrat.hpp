/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/13 02:15:40 by itopchu       #+#    #+#                 */
/*   Updated: 2023/10/13 02:15:40 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include "main.hpp"
# include "AForm.hpp"
# include <string>
# include <exception>

class AForm;

class Bureaucrat
{
	private:
		std::string const	__name;
		int					__grade;
	public:
		// Form
		Bureaucrat(void);
		virtual ~Bureaucrat(void);
		Bureaucrat(Bureaucrat const & copy);
		Bureaucrat& operator=(Bureaucrat const & assign);
		// Subject
		Bureaucrat(std::string const &name, int const &grade);
		std::string const & getName(void) const;
		int const & getGrade(void) const;
		void increaseGrade();
		void decreaseGrade();
		void signForm(AForm& form);
		void executeForm(AForm const & form);
		// Exceptions
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
	friend std::ostream &operator<<(std::ostream &outs, Bureaucrat const &bureau);
};

#endif