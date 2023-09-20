/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongCat.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/20 22:15:13 by itopchu       #+#    #+#                 */
/*   Updated: 2023/09/20 22:15:13 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		//Form
		WrongCat(void);
		~WrongCat(void);
		// Member functions
		void   makeSound(void) const;
	private:
	protected:
};

#endif