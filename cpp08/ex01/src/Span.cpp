/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Span.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/25 20:58:33 by itopchu       #+#    #+#                 */
/*   Updated: 2023/10/25 20:58:33 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) :
	__maxSize(1)
{
	__data.reserve(1);
}

Span::Span(unsigned int n) :
	__maxSize(n)
{
	__data.reserve(n);
}

Span::~Span(void) {}

Span::Span(Span const & copy) :
	__data(copy.__data),
	__maxSize(copy.__maxSize)
{

}

Span& Span::operator=(Span const & assign)
{
	if (this != &assign)
	{
		__maxSize = assign.__maxSize;
		__data = assign.__data;
	}
	return (*this);
}

void	Span::addNumber(int val)
{
	if (__data.size() >= __maxSize)
		throw NoSpaceException();
	__data.push_back(val);
}

int		Span::shortestSpan(void) const
{
	if (__data.size() <= 1)
		throw NoSpanException();
	int shortest = std::numeric_limits<int>::max();
	for (size_t i = 0; i < __data.size(); ++i)
	{
		for (size_t j = i + 1; j < __data.size(); ++j)
		{
			int span = std::abs(__data[j] - __data[i]);
			if (span < shortest)
				shortest = span;
		}
	}
	return shortest;
}

int		Span::longestSpan(void) const
{
	if (__data.size() <= 1)
		throw NoSpanException();
	int min = *std::min_element(__data.begin(), __data.end());
	int max = *std::max_element(__data.begin(), __data.end());
	return (max - min);
}

void	Span::addNumbers(const std::vector<int>& container)
{
	    if (__data.size() + container.size() > __maxSize)
            throw NoSpaceException();
        __data.insert(__data.end(), container.begin(), container.end());
}

const char	*Span::NoSpaceException ::what() const throw()
{
	return "maxSize is not big enough to do this!";
}

const char	*Span::NoSpanException ::what() const throw()
{
	return "Container doesn't have enough elements! ";
}
