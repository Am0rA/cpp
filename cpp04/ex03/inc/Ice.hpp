/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Ice.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/29 23:13:08 by itopchu       #+#    #+#                 */
/*   Updated: 2023/09/29 23:13:08 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
	public:
	    Ice() : AMateria("ice") {}
	    virtual ~Ice() {}
	    AMateria* clone() const { return new Ice(); }
	    void use(ICharacter& target);
};

#endif