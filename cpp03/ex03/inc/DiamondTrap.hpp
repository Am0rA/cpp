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

class DiamondTrap: public FragTrap, public ScavTrap
{
	public:
		using FragTrap::_hp;
		using FragTrap::_ap;
		using FragTrap::_ep;
		using FragTrap::attack;
		DiamondTrap();
		DiamondTrap(const DiamondTrap &copy);
		~DiamondTrap();
		DiamondTrap&	operator=(const DiamondTrap &other);
		void	whoAmI(void) const;
		// void	attack(const std::string &target) const;
	private:
		std::string	_name;
};

#endif