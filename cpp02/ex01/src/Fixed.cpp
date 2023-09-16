/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 13:06:28 by itopchu       #+#    #+#                 */
/*   Updated: 2023/08/31 13:06:28 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default Constructor called of Fixed" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy Constructor called of Fixed" << std::endl;
	*this = copy;
}

Fixed::Fixed(const int value) : _value(value << _bits)
{
	std::cout << "Int Constructor called of Fixed" << std::endl;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float Constructor called of Fixed" << std::endl;
	_value = roundf(value * (1 << _bits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called of Fixed" << std::endl;
}

float Fixed::toFloat(void) const
{
	return (float)_value / (1 << _bits);
}

int	Fixed::toInt(void) const
{
	return _value >> _bits;
}

std::ostream &operator<<(std::ostream &outs, Fixed const &i)
{
	outs << i.toFloat();
	return outs;
}

Fixed &Fixed::operator=(const Fixed &assign)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &assign)
		setRawBits(assign.getRawBits());
	return (*this);
}

int Fixed::getRawBits(void) const
{
	return (_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}
