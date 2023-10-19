/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/18 19:41:04 by itopchu       #+#    #+#                 */
/*   Updated: 2023/10/18 19:41:04 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string const	__name;
		std::string const	__target;
		int const			__recuiredGrade;
		int const			__executeGrade;
		bool				__sign;
	public:
		// AForm
		AForm(void);
		virtual ~AForm(void);
		AForm(const AForm& copy);
		AForm& operator=(const AForm& assign);
		// Subject
		AForm(std::string const & name, std::string const & target, int recuiredGrade, int executeGrade);
		void				beSigned(const Bureaucrat& bureaucrat);
		void				setSign(bool condition);
		std::string const &	getName(void) const;
		std::string const &	getTarget(void) const;
		bool const &		getSign(void) const;
		int const &			getRecuired(void) const;
		int const &			getExecute(void) const;
		virtual void		execute(Bureaucrat const &executor) const = 0;
	class	GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
	class	GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
	class NotSignedException : public std::exception {
		public:
			virtual const char *what() const throw();
	};
	friend std::ostream & operator<<(std::ostream &o, AForm const &ref);
};

#endif