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

class ScavTrap : public ClapTrap
{
	public:
		// Form
		ScavTrap();
		ScavTrap(std::string _name);
		ScavTrap(const ScavTrap &copy);
		virtual ~ScavTrap();
		ScavTrap & operator=(const ScavTrap &assign);
		// Member functions
		void	guardGate(void);
		void	attack(const std::string& target);
	private:
	protected:
		static const unsigned int DEFAULT_HP = 10;
		static const unsigned int DEFAULT_EP = 10;
		static const unsigned int DEFAULT_AP = 0;
		static const std::string DEFAULT_NAME;
};

#endif