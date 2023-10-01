/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Character.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/30 19:56:40 by itopchu       #+#    #+#                 */
/*   Updated: 2023/09/30 19:56:40 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		AMateria*	mp__inventory[4];
		std::string	m__name;
	public:
		// Form
		Character(void);
		~Character(void);
		Character(Character const & copy);
		Character& operator=(Character const & assign);
		// Subject Part
		Character(std::string const & name);
		std::string const & getName(void) const;
		void	equip(AMateria* m);
		void	unequip(int idx);
		void	use(int idx, ICharacter& target);
};

#endif
