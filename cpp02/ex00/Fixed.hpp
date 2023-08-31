/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 13:06:08 by itopchu       #+#    #+#                 */
/*   Updated: 2023/08/31 13:06:08 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &copy);
		Fixed(int value);
		~Fixed();
		Fixed & operator=(const Fixed &assign);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		int 				_value;
		static const int	_bits = 8;
};

#endif