/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/15 03:25:35 by itopchu       #+#    #+#                 */
/*   Updated: 2023/10/15 03:25:35 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include "Bureaucrat.hpp"
# include <string>
# include <sstream>
# include <stdbool.h>

class Form
{
	private:
		const std::string	mc__name;
		const int			mc__recuiredGrade;
		const int			mc__executeGrade;
		bool				m__sign;
	public:
		// Form
		Form(void);
		~Form(void);
		Form(Form const & copy);
		Form& operator=(Form const & assign);
		// Subject
		Form(std::string const &name, int recuired, int execute);
		void	beSigned(const int &ref);
		std::string const	&getName(void) const;
		bool const			&getSign(void) const;
		int const			&getRecuired(void) const;
		int const			&getExecute(void) const;
		// Exceptions
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Grade is too high for the form.";
				}
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Grade is too low for the form.";
				}
		};
		friend std::ostream &operator<<(std::ostream &outs, Form const &form);
};

#endif