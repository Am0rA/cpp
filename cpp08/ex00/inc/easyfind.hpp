/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   easyfind.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/25 18:26:19 by itopchu       #+#    #+#                 */
/*   Updated: 2023/10/25 18:26:19 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <iostream>
# include <vector>
# include <list>
# include <set>
# include <map>
# include <algorithm>

class NotFoundException: public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("Element not found");
		}
};

// Function template easyfind
// Accepts a container of type T and an integer value.
// Searches for the first occurrence of the integer value in the container.
// If found, returns an iterator pointing to the found element.
// If not found, throws a NotFoundException.
template <typename T>
typename T::iterator easyfind(T& container, int n)
{
	typename T::iterator it;
	// std::find is a simple, general, efficent, consistent and easy to maintain
	it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
		throw (NotFoundException());
	return it;
}

#endif