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
		// Constructors
		ClapTrap();
		ClapTrap(const ClapTrap &copy);
		ClapTrap(std::string _name, unsigned int p_hit, unsigned int p_energy, unsigned int p_attack);
		
		// Destructor
		~ClapTrap();
		
		// Operators
		ClapTrap & operator=(const ClapTrap &assign);
		
		// Getters / Setters
		std::string getName() const;
		void set_name(std::string _name);
		unsigned int getP_hit() const;
		void setP_hit(unsigned int p_hit);
		unsigned int getP_energy() const;
		void setP_energy(unsigned int p_energy);
		unsigned int getP_attack() const;
		void setP_attack(unsigned int p_attack);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		
	private:
		std::string _name;
		unsigned int _p_hit;
		unsigned int _p_energy;
		unsigned int _p_attack;
		
};

#endif