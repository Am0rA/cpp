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
		bool	operator<(const Fixed &other) const;
		bool	operator>(const Fixed &other) const;
		bool	operator>=(const Fixed &other) const;
		bool	operator<=(const Fixed &other) const;
		bool	operator==(const Fixed &other) const;
		bool	operator!=(const Fixed &other) const;
		Fixed	operator+(const Fixed &other) const;
		Fixed	operator-(const Fixed &other) const;
		Fixed	operator*(const Fixed &other) const;
		Fixed	operator/(const Fixed &other) const;
		// Prefix
		Fixed	&operator++(void);
		Fixed	&operator--(void);
		// Postfix
		Fixed	operator++(int);
		Fixed	operator--(int);
    	static Fixed& min(Fixed &a, Fixed &b);
    	static const Fixed& min(const Fixed &a, const Fixed &b);
    	static Fixed& max(Fixed &a, Fixed &b);
    	static const Fixed& max(const Fixed &a, const Fixed &b);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

	private:
		int 				_value;
		static const int	_bits = 8;
};

std::ostream &operator<<(std::ostream &outs, Fixed const &i);

#endif