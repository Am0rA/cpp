/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 13:07:16 by itopchu       #+#    #+#                 */
/*   Updated: 2023/08/31 13:07:16 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

# define RED "\e[1;31m"
# define BLUE "\e[1;34m"
# define GREEN "\e[1;32m"
# define YELLOW "\e[0;33m"
# define PURP "\e[0;35m"
# define L_BLUE "\e[1;36m"
# define DEFCOLOR "\033[0m"

class ClapTrap
{
	public:
		// Form
		ClapTrap();
		ClapTrap(const ClapTrap &copy);
		ClapTrap(std::string _name);
		~ClapTrap();
		ClapTrap & operator=(const ClapTrap &assign);

		// Getters
		std::string getName() const;
		unsigned int getHitPoint() const;
		unsigned int getEnergyPoint() const;
		unsigned int getAttackPoint() const;
		
		// Setters
		void setName(std::string _name);
		void setHitPoint(unsigned int p_hit);
		void setEnergyPoint(unsigned int p_energy);
		void setAttackPoint(unsigned int p_attack);

		// Static getters
		static std::string		getClassName(void);
		static unsigned int		getClassHitPoint(void);
		static unsigned int		getClassEnergyPoint(void);
		static unsigned int		getClassAttackPoint(void);

		// Member functions
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		
	private:
		// Object attributes
		std::string _name;
		unsigned int _hp;
		unsigned int _ep;
		unsigned int _ap;
		
		// Class attributes
		static const std::string _c_name;
		static const unsigned int _c_hp;
		static const unsigned int _c_ep;
		static const unsigned int _c_ap;
};

#endif