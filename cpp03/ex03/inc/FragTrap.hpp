/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/04 23:40:26 by itopchu       #+#    #+#                 */
/*   Updated: 2023/09/04 23:40:26 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		// Form
		FragTrap();
		FragTrap(std::string _name);
		FragTrap(const FragTrap &copy);
		virtual ~FragTrap();
		FragTrap & operator=(const FragTrap &assign);
		// Member functions
		void	highFivesGuys(void);
	private:
	protected:
		static const unsigned int DEFAULT_HP = 100;
		static const unsigned int DEFAULT_EP = 100;
		static const unsigned int DEFAULT_AP = 30;
		static const std::string DEFAULT_NAME;
};

#endif