/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   DiamondTrap.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/06 01:16:36 by itopchu       #+#    #+#                 */
/*   Updated: 2023/09/06 01:16:36 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap: virtual public FragTrap, virtual public ScavTrap
{
    public:
		// Form
        DiamondTrap();
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap &copy);
        ~DiamondTrap();
        DiamondTrap& operator=(const DiamondTrap &other);
		// Member functions
		void whoAmI(void) const;
		// derived declarations
		using ScavTrap::attack;
		// Static getters
		static std::string		getClassName(void);
		static unsigned int		getClassHitPoint(void);
		static unsigned int		getClassEnergyPoint(void);
		static unsigned int		getClassAttackPoint(void);
    private:
		// Class attributes
		static const std::string _c_name;
        std::string _name;
};

#endif