/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   iter.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/24 04:04:29 by itopchu       #+#    #+#                 */
/*   Updated: 2023/10/24 04:04:29 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>

template <typename T>
void iter(T* array, size_t length, void(*f)(T& arg))
{
	if (!array)
		return ;
    for (size_t i = 0; i < length; ++i)
        f(array[i]);
}

template <typename T>
void printElement(T & txt)
{
	std::cout << txt;
}

#endif