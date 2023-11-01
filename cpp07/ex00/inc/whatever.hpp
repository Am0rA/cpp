/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   whatever.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/24 03:47:47 by itopchu       #+#    #+#                 */
/*   Updated: 2023/10/24 03:47:47 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template<typename T>
void	swap(T &arg1, T &arg2)
{
	T temp = arg1;
	arg1 = arg2;
	arg2 = temp;
}

template<typename T>
T 	min(T &val1, T &val2)
{
	return val1 < val2 ? val1 : val2;
}

template<typename T>
T 	max(T &val1, T &val2)
{
	return val1 > val2 ? val1 : val2;
}

#endif