/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MateriaSource.hpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/29 23:17:08 by itopchu       #+#    #+#                 */
/*   Updated: 2023/09/29 23:17:08 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		std::array<AMateria*, 4> _materias;

	public:
		MateriaSource() : _materias{nullptr, nullptr, nullptr, nullptr} {}
		virtual ~MateriaSource();

		void learnMateria(AMateria* m);
		AMateria* createMateria(std::string const & type);
};

#endif