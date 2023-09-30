/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cure.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/29 23:14:03 by itopchu       #+#    #+#                 */
/*   Updated: 2023/09/29 23:14:03 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria {
	public:
		Cure() : AMateria("cure") {}
    	virtual ~Cure() {}
    	AMateria* clone() const { return new Cure(); }
    	void use(ICharacter& target);
};

#endif