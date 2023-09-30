/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AMateria.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/27 11:03:33 by itopchu       #+#    #+#                 */
/*   Updated: 2023/09/27 11:03:33 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "main.hpp"
class ICharacter;

class AMateria
{
	protected:
	    std::string _type;

	public:
	    AMateria(std::string const & type) : _type(type) {}
	    virtual ~AMateria() {}

	    std::string const & getType() const { return _type; }
	    virtual AMateria* clone() const = 0;
	    virtual void use(ICharacter& target);
};

#endif
