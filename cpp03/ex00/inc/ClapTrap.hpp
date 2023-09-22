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
# include "main.hpp"

class ClapTrap
{
	public:
		// Form
		ClapTrap();
		ClapTrap(const ClapTrap &copy);
		ClapTrap(std::string _name);
		virtual ~ClapTrap();
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
	
	protected:
		static const unsigned int DEFAULT_HP = 100;
		static const unsigned int DEFAULT_EP = 50;
		static const unsigned int DEFAULT_AP = 20;
		static const std::string DEFAULT_NAME;
};

#endif