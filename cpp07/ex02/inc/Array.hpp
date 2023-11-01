/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Array.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/25 04:02:46 by itopchu       #+#    #+#                 */
/*   Updated: 2023/10/25 04:02:46 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>
# include <stdexcept>

template<typename T>
class Array
{
	private:
		unsigned int	__size;
		T*			__array;
	public:
		Array() : __size(0), __array(NULL) {}
		Array(unsigned int size) : __size(size), __array(new T[size]) {}
		~Array() {delete[] __array;}
		Array(Array const & copy) : __size(copy.__size), __array(new T[copy.__size])
		{for (unsigned int i = 0; i < __size; i++) __array[i] = copy.__array[i];}
		Array& operator=(Array const & assign)
		{
			if (this != assign)
			{
				delete[] __array;
				__size = assign.__size;
				__array = new T[assign.__size];
				for (unsigned int i = 0; i < __size; i++) {__array[i] = assign.__array[i];}
			}
			return *this;
		}
		T& operator[](unsigned int index) const
		{
			if (index >= __size) throw std::out_of_range("Index of range");
			return (__array[index]);
		}
		unsigned int size() const {return __size;}
};

#endif