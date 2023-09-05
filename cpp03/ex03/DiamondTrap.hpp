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

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap
{
	public:
		DiamondTrap();
		DiamondTrap(const std::string &copy);
		~DiamondTrap();
		DiamondTrap&	operator=(const DiamondTrap &other);
		void	attack(const std::string &target) const;
		void	whoAmI(void) const;
	private:
		std::string	_name;
};

#endif