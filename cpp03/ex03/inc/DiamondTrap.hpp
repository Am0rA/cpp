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
    private:
		// Class attributes
        std::string _name;
	protected:
		static const unsigned int DEFAULT_HP = FragTrap::DEFAULT_HP;
		static const unsigned int DEFAULT_EP = ScavTrap::DEFAULT_EP;
		static const unsigned int DEFAULT_AP = FragTrap::DEFAULT_AP;
		static const std::string DEFAULT_NAME;
};

#endif