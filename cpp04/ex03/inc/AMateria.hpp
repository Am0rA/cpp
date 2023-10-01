/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AMateria.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/30 19:25:15 by itopchu       #+#    #+#                 */
/*   Updated: 2023/09/30 19:25:15 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include "main.hpp"

class ICharacter;

class AMateria
{
	private:
		// Form
		AMateria(void);
	public:
		// Form
		virtual ~AMateria();
		AMateria(AMateria const & copy);
		AMateria& operator=(AMateria const & assign);

		// Subject members
		AMateria(std::string const & type);
		std::string const & getType(void) const;
		virtual AMateria* clone(void) const = 0;
		virtual void use(ICharacter& target);
	protected:
		std::string	m_type;
};

#endif
