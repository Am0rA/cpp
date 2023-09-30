/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongAnimal.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/20 22:07:47 by itopchu       #+#    #+#                 */
/*   Updated: 2023/09/20 22:07:47 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include "main.hpp"

class WrongAnimal
{
	protected:
		std::string _type;
	public:
		// Form
		WrongAnimal(void);
		WrongAnimal(const std::string type);
		WrongAnimal(const WrongAnimal& copy);
		~WrongAnimal(void);
		WrongAnimal& operator=(const WrongAnimal& assign);
		// Member functions
		void		makeSound(void) const;
		std::string	getType(void) const;
	private:

};

#endif