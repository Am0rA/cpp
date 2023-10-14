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

# define RED "\e[1;31m"
# define BLUE "\e[1;34m"
# define GREEN "\e[1;32m"
# define YELLOW "\e[0;33m"
# define PURP "\e[0;35m"
# define L_BLUE "\e[1;36m"
# define DEFCOLOR "\033[0m"
# include <iostream>
# include <string>
# include <sstream>

class Bureaucrat
{
	private:
		std::string	m__name;
		int			m__grade;
		static int	ms__amount;
	public:
		// Form
		Bureaucrat(void);
		~Bureaucrat(void);
		Bureaucrat(Bureaucrat const & copy);
		Bureaucrat& operator=(Bureaucrat const & assign);
		// Subject
		Bureaucrat(std::string const &name, int const &grade);
		std::string const & getName(void) const;
		int const & getGrade(void) const;
		void increaseGrade(int amount);
		void decreaseGrade(int amount);
		// Exceptions
		class GradeTooLowException : public std::exception
		{
			private:
				std::string message;
			public:
				GradeTooLowException(int amount);
				virtual ~GradeTooLowException() throw();
				virtual const char	*what() const throw();
		};
		class GradeTooHighException : public std::exception
		{
			private:
				std::string message;
			public:
				GradeTooHighException(int amount);
				virtual ~GradeTooHighException() throw();
				virtual const char	*what() const throw();
		};
};

//Subject
std::ostream &operator<<(std::ostream &outs, Bureaucrat const &bureau);

#endif