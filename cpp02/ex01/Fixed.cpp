#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default Constructor called of Fixed" << std::endl;
	_value = 0;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy Constructor called of Fixed" << std::endl;
	*this = copy;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int Constructor called of Fixed" << std::endl;
	_value = value << _bits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float Constructor called of Fixed" << std::endl;
	_value = (int)(roundf(value * (1 << _bits)));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called of Fixed" << std::endl;
}

float	Fixed::toFloat(void) const
{
	return ((float)_value / (float)(1 << _bits));
}

int	Fixed::toInt(void) const
{
	return (this->_value >> _bits);
}

std::ostream &operator<<(std::ostream &outs, Fixed const &i)
{
    outs << i.toFloat();
    return (outs);
}

Fixed &Fixed::operator=(const Fixed &assign)
{
    std::cout << "Copy assignment operator called" << std::endl;
	if (this != &assign)
		_value = assign.getRawBits();
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
