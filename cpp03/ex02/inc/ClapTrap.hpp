/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 13:07:52 by itopchu       #+#    #+#                 */
/*   Updated: 2023/08/31 13:07:52 by itopchu       ########   odam.nl         */
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
		ClapTrap();
		ClapTrap(const ClapTrap &copy);
		ClapTrap(std::string _name, unsigned int p_hit, unsigned int p_energy, unsigned int p_attack);
		~ClapTrap();
		ClapTrap & operator=(const ClapTrap &assign);
		
		std::string getName() const;
		void setName(std::string _name);
		unsigned int getHitPoint() const;
		void setHitPoint(unsigned int p_hit);
		unsigned int getEnergyPoint() const;
		void setEnergyPoint(unsigned int p_energy);
		unsigned int getAttackPoint() const;
		void setAttackPoint(unsigned int p_attack);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		
	private:
		std::string _name;
		unsigned int _hp;
		unsigned int _ep;
		unsigned int _ap;
		
};

#endif