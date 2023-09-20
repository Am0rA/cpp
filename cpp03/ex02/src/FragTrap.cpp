/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/04 23:38:09 by itopchu       #+#    #+#                 */
/*   Updated: 2023/09/04 23:38:09 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

const std::string	FragTrap::_c_name = "FragTrap";
const unsigned int	FragTrap::_c_hp = 100;
const unsigned int	FragTrap::_c_ep = 100;
const unsigned int	FragTrap::_c_ap = 30;

FragTrap::FragTrap() : ClapTrap(FragTrap::_c_name)
{
    std::cout << YELLOW "Default FragTrap Constructor called" DEFCOLOR << "\n";
    setHitPoint(FragTrap::_c_hp);
    setEnergyPoint(FragTrap::_c_ep);
    setAttackPoint(FragTrap::_c_ap);
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << YELLOW "FragTrap Constructor called" DEFCOLOR << "\n";
    setHitPoint(FragTrap::_c_hp);
    setEnergyPoint(FragTrap::_c_ep);
    setAttackPoint(FragTrap::_c_ap);
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
    std::cout << YELLOW "FragTrap Copy Constructor called" DEFCOLOR << std::endl;
    *this = copy;
}

FragTrap::~FragTrap()
{
    std::cout << PURP "FragTrap Destructor called" DEFCOLOR << "\n";
}

FragTrap & FragTrap::operator=(const FragTrap &assign)
{
    setName(assign.getName());
    setHitPoint(assign.getHitPoint());
    setEnergyPoint(assign.getEnergyPoint());
    setAttackPoint(assign.getAttackPoint());
    return *this;
}

// Static getters
std::string FragTrap::getClassName() 
{
    return _c_name;
}

unsigned int FragTrap::getClassHitPoint() 
{
    return _c_hp;
}

unsigned int FragTrap::getClassEnergyPoint() 
{
    return _c_ep;
}

unsigned int FragTrap::getClassAttackPoint() 
{
    return _c_ap;
}

void FragTrap::highFivesGuys(void)
{
    std::string name = getName();
    std::string padding = std::string(name.length() + 6, ' '); 

    std::cout << "I am " BLUE << name << DEFCOLOR << "." \
			  << GREEN "           .%         ╔═══════════════════════════╗\n" DEFCOLOR \
			  << padding << GREEN "         ,*,       .%," YELLOW "║Would you like a High five?║\n" GREEN \
			  << padding << "        ,;,,     ,?.  ╚═══════════════════════════╝\n" \
			  << padding << "    %$::$@@@*;+  ,@.\n" \
			  << padding << "    ?$::@" BLUE "++" GREEN "@?:;  .#.\n" \
			  << padding << "   .@$::@" BLUE "++" GREEN "@::.  .#.\n" \
			  << padding << "   # $..*@@+.*$%?\n" \
			  << padding << "  %  $...##.;\n" \
			  << padding << "%,   #::?%#;:\n" \
			  << padding << "?$,  #::?&%::\n" \
			  << padding << "  $  #::###:$\n" \
			  << padding << "     ,#:#$$#:\n" \
			  << padding << "     ,#$$$$#:\n" \
			  << padding << "     .######\n" \
			  << padding << "      .@@@;\n" \
			  << padding << "     .@@+@@\n" \
			  << padding << "      .@#@\n" DEFCOLOR;
}
