#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

# define GRAY "\033[30m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define WHITE "\033[37m"

class Harl
{
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
		void	def(void);
	public:
		Harl();
		~Harl();
		void	complain(std::string level);
};

#endif