/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 13:06:03 by itopchu       #+#    #+#                 */
/*   Updated: 2023/08/31 13:06:03 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default Constructor called of Fixed" << std::endl;
	_value = 0;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy Constructor called of Fixed" << std::endl;
	_value = copy.getRawBits();
}

Fixed & Fixed::operator=(const Fixed &assign)
{
    std::cout << "Copy assignment operator called" << std::endl;
	if (this != &assign)
		this->_value = assign.getRawBits();
	return *this;
}

Fixed::Fixed(int value)
{
	std::cout << "Fields Constructor called of Fixed" << std::endl;
	_value = value;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called of Fixed" << std::endl;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _bits;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}
