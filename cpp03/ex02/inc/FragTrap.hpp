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
		FragTrap(std::string name);
		FragTrap(const FragTrap &copy);
		~FragTrap();
		FragTrap & operator=(const FragTrap &assign);
		// Member functions
		void	highFivesGuys(void);
		// Static getters
		static std::string		getClassName(void);
		static unsigned int		getClassHitPoint(void);
		static unsigned int		getClassEnergyPoint(void);
		static unsigned int		getClassAttackPoint(void);
	private:
		// Class attributes
		static const std::string _c_name;
		static const unsigned int _c_hp;
		static const unsigned int _c_ep;
		static const unsigned int _c_ap;
};

#endif