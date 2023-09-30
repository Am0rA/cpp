/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/20 21:44:25 by itopchu       #+#    #+#                 */
/*   Updated: 2023/09/20 21:44:25 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	public:
		//Form
		Cat(void);
		Cat(const Cat &assign);
		Cat &operator=(const Cat &assign);
		~Cat(void);
		// Member functions
		void makeSound() const;
	private:
		Brain*	brain;
	protected:
};

#endif