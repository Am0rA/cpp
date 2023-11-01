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

template <typename T>
typename T::iterator easyfind(T& container, int n)
{
	typename T::iterator it;
	it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
		throw (NotFoundException());
	return it;
}

#endif