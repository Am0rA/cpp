/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MutantStack.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/29 20:51:08 by itopchu       #+#    #+#                 */
/*   Updated: 2023/10/29 20:51:08 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		using std::stack<T>::c;

		class iterator : public std::deque<T>::iterator
		{
			public:
				iterator(typename std::deque<T>::iterator it) : std::deque<T>::iterator(it) {}
		};

		iterator begin() { return iterator(c.begin()); }

		iterator end() { return iterator(c.end());}

		class const_iterator : public std::deque<T>::const_iterator
		{
			public:
				const_iterator(typename std::deque<T>::const_iterator it) : std::deque<T>::const_iterator(it) {}
		};

		const_iterator begin() const { return const_iterator(c.begin()); }

		const_iterator end() const { return const_iterator(c.end()); }
};

#endif