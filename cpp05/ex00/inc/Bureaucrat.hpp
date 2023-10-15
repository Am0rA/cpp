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
			public:
				virtual const char	*what() const throw();
		};
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
};

//Subject
std::ostream &operator<<(std::ostream &outs, Bureaucrat const &bureau);

#endif