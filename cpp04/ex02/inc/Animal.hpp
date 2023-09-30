/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/20 18:32:42 by itopchu       #+#    #+#                 */
/*   Updated: 2023/09/20 18:32:42 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include "main.hpp"

class Animal
{
	protected:
		std::string _type;
		Animal(void);
		Animal(const std::string type);
		Animal(const Animal& copy);
	public:
		// Form
		Animal& operator=(const Animal& assign);
		virtual ~Animal(void);
		// Member functions
		virtual void	makeSound(void) const;
		std::string		getType(void) const;
	private:
};

#endif