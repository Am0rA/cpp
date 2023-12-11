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

Span::Span(void) : __maxSize(1) { }

Span::Span(unsigned int n) : __maxSize(n) { }

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
	__data.insert(val);
}

int		Span::shortestSpan(void) const
{
	if (__data.size() <= 1)
		throw NoSpanException();

	std::multiset<int>::const_iterator prev = __data.begin();
	std::multiset<int>::const_iterator curr = prev;
	curr++;
	unsigned int minSpan = static_cast<unsigned int>(*curr) - static_cast<unsigned int>(*prev);
	while (curr != __data.end())
	{
		unsigned int tmp = static_cast<unsigned int>(*curr) - static_cast<unsigned int>(*prev);
		if (tmp < minSpan)
			minSpan = tmp;
		curr++;
		prev++;
	}
	return (minSpan);
}

int Span::longestSpan(void) const
{
	if (__data.size() <= 1)
		throw NoSpanException();
	return (std::abs(*__data.rbegin() - *__data.begin()));
}

void	Span::addNumbers(const std::multiset<int>& container)
{
	if (__data.size() + container.size() > __maxSize)
		throw NoSpaceException();
	__data.insert(container.begin(), container.end());
}

void	Span::addNumbers(unsigned int size)
{
	if (size + __data.size() > __maxSize)
		throw NoSpaceException();
	if (size > 200000)
	{
		size = 200000;
		std::cout << "Only 200.000 elements will be added to __data\n";

	}
    std::random_device rd;
    std::mt19937_64  gen(rd());
    std::uniform_int_distribution<int> distribution(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());

    for (unsigned int i = 0; i < size; ++i) {
        int randomElement = static_cast<int>(distribution(gen));
        __data.insert(randomElement);
    }
}

const char	*Span::NoSpaceException ::what() const throw()
{
	return "Insufficient space in the container";
}

const char	*Span::NoSpanException ::what() const throw()
{
	return "Insufficient elements in the container";
}
