/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 13:06:51 by itopchu       #+#    #+#                 */
/*   Updated: 2023/08/31 13:06:51 by itopchu       ########   odam.nl         */
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

bool	Fixed::operator<(const Fixed &other) const
{
	return (other.getRawBits() < this->getRawBits());
}

bool	Fixed::operator>(const Fixed &other) const
{
	return (other.getRawBits() > this->getRawBits());
}

bool	Fixed::operator>=(const Fixed &other) const
{
	return (other.getRawBits() >= this->getRawBits());
}

bool	Fixed::operator<=(const Fixed &other) const
{
	return (other.getRawBits() <= this->getRawBits());
}

bool	Fixed::operator==(const Fixed &other) const
{
	return (other.getRawBits() == this->getRawBits());
}

bool	Fixed::operator!=(const Fixed &other) const
{
	return (other.getRawBits() != this->getRawBits());
}

Fixed	Fixed::operator+(const Fixed &other) const
{
	return (this->toFloat() + other.toFloat());
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	return (this->toFloat() - other.toFloat());
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	return (this->toFloat() * other.toFloat());
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	return (this->toFloat() / other.toFloat());
}

Fixed	&Fixed::operator++(void)
{
	++this->_value;
	return (*this);
}

Fixed	&Fixed::operator--(void)
{
	--this->_value;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	ret(*this);
	operator++();
	return (ret);
}

Fixed	Fixed::operator--(int)
{
	Fixed	ret(*this);
	operator--();
	return (ret);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (b.getRawBits() < a.getRawBits())
		return (b);
	return (a);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (b.getRawBits() > a.getRawBits())
		return (b);
	return (a);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (b.getRawBits() < a.getRawBits())
		return (b);
	return (a);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (b.getRawBits() > a.getRawBits())
		return (b);
	return (a);
}
