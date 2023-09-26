/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/20 21:50:29 by itopchu       #+#    #+#                 */
/*   Updated: 2023/09/20 21:50:29 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
	public:
		//Form
		Dog(void);
		Dog(const Dog &assign);
		Dog &operator=(const Dog &assign);
		~Dog(void);
		// Member functions
		void makeSound() const;
	private:
	protected:
};

#endif