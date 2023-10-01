/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Ice.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/30 19:28:43 by itopchu       #+#    #+#                 */
/*   Updated: 2023/09/30 19:28:43 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP
# include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		// Form
		Ice();
		~Ice();
		Ice(Ice const & copy);
		Ice& operator=(Ice const & assign);
		// Subject part
		AMateria*	clone(void) const;
		void	use(ICharacter& target);
};

#endif
