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

const std::string FragTrap::DEFAULT_NAME = "FragTrap";

FragTrap::FragTrap() :
	ClapTrap(DEFAULT_NAME)
{
	std::cout << YELLOW "A FragTrap called " << FragTrap::DEFAULT_NAME << " is constructed" DEFCOLOR << std::endl;
    setHitPoint(DEFAULT_HP);
    setEnergyPoint(DEFAULT_EP);
    setAttackPoint(DEFAULT_AP);
}

FragTrap::FragTrap(std::string _name) : ClapTrap(_name)
{
	std::cout << YELLOW "A FragTrap called " << _name << " is constructed" DEFCOLOR << std::endl;
    setHitPoint(DEFAULT_HP);
    setEnergyPoint(DEFAULT_EP);
    setAttackPoint(DEFAULT_AP);
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
    std::cout << YELLOW "A copy FragTrap of " << copy.getName() << " is constructed" DEFCOLOR << std::endl;
    *this = copy;
}

FragTrap::~FragTrap()
{
	std::cout << PURP "A FragTrap called " << this->getName() << " is deconstructed" DEFCOLOR << std::endl;
}

FragTrap & FragTrap::operator=(const FragTrap &assign)
{
    setName(assign.getName());
    setHitPoint(assign.getHitPoint());
    setEnergyPoint(assign.getEnergyPoint());
    setAttackPoint(assign.getAttackPoint());
    return *this;
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
