/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 21:41:31 by itopchu       #+#    #+#                 */
/*   Updated: 2023/08/31 21:41:31 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		// Form
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &copy);
		~ScavTrap();
		ScavTrap & operator=(const ScavTrap &assign);
		// Member functions
		void	guardGate(void);
		void	attack(const std::string& target);

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