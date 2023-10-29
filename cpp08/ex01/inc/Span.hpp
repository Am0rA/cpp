/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Span.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/25 20:58:30 by itopchu       #+#    #+#                 */
/*   Updated: 2023/10/25 20:58:30 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

class Span
{
	private:
		std::vector<int>	__data;
		unsigned int		__maxSize;
	public:
		Span(void);
		Span(unsigned int n);
		~Span(void);
		Span(Span const & copy);
		Span &operator=(Span const & assign);
		void	addNumber(int val);
		void	addNumbers(const std::vector<int>& container);
		int		shortestSpan(void) const;
		int		longestSpan(void) const;
	class NoSpaceException : public std::exception {
		public:
			virtual char const *what() const throw();
	};

	class NoSpanException : public std::exception {
		public:
			virtual char const *what() const throw();
	};
};
