/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/18 19:41:04 by itopchu       #+#    #+#                 */
/*   Updated: 2023/10/18 19:41:04 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const	__name;
		int const			__recuiredGrade;
		int const			__executeGrade;
		bool				__sign;
	public:
		// Form
		Form(void);
		virtual ~Form(void);
		Form(const Form& copy);
		Form& operator=(const Form& assign);
		// Subject
		Form(std::string const & name, int recuiredGrade, int executeGrade);
		void				beSigned(const Bureaucrat& bureaucrat);
		std::string const &	getName(void) const;
		bool const &		getSign(void) const;
		int const &			getRecuired(void) const;
		int const &			getExecute(void) const;
	class	GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
	class	GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
	friend std::ostream & operator<<(std::ostream &o, Form const &ref);
};

#endif