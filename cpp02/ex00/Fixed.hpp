#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed
{
	public:
		// Constructors
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