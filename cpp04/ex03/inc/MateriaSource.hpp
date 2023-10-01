/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MateriaSource.hpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/30 20:05:54 by itopchu       #+#    #+#                 */
/*   Updated: 2023/09/30 20:05:54 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria*	mp__materias[4];
	public:
		// Form
		MateriaSource(void);
		~MateriaSource(void);
		MateriaSource(MateriaSource const & copy);
		MateriaSource& operator=(MateriaSource const & assign);
		// Subject part
		void	learnMateria(AMateria* m);
		AMateria*	createMateria(std::string const & type);
};

#endif
