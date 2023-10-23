/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/21 19:27:35 by itopchu       #+#    #+#                 */
/*   Updated: 2023/10/21 19:27:35 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include "main.hpp"
# include <iostream>
# include <stdexcept>
# include <sstream>
# include <cmath>
# include <limits>
# include <climits>
# include <cstdlib>
# include <cctype>

# define INT 1
# define FLOAT 2
# define DOUBLE 3
# define CHAR 4
# define NAN_INF 5
# define ERROR 6

class ScalarConverter
{
	private:
		static void putChar(void);
		static void putInt(void);
		static void putFloat(void);
		static void putDouble(void);
		static void	findType(void);
		static void fillValues(void);
		static int			__type;
		static std::string	__input;
		static int			__int;
		static float		__float;
		static char			__char;
		static double		__double;
	public:
		static void convert(const std::string& input);
};

#endif