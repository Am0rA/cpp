#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
	public:
		// Constructors
		Fixed();
		Fixed(const Fixed &copy);
		Fixed &operator=(const Fixed &assign);
		Fixed(const int value);
		Fixed(const float value);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

	private:
		int 				_value;
		static const int	_bits = 8;
};

std::ostream &operator<<(std::ostream &o, Fixed const &i);

#endif