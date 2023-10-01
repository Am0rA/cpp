/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cure.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/30 19:28:17 by itopchu       #+#    #+#                 */
/*   Updated: 2023/09/30 19:28:17 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP
# include "AMateria.hpp"

class Cure : public AMateria
{
	private:
		/* data */
	public:
		// Form
		Cure();
		~Cure();
		Cure(Cure const & copy);
		Cure& operator=(Cure const & assign);
		// Subject part
		AMateria*	clone(void) const;
		void	use(ICharacter& target);
};

#endif
