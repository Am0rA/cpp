/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/25 21:41:23 by itopchu       #+#    #+#                 */
/*   Updated: 2023/09/25 21:41:23 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include "main.hpp"
# include <string>

class Brain
{
	public:
		// Form
		Brain(void);
		Brain(const Brain& copy);
		~Brain(void);
		Brain& operator=(const Brain& assign);
		std::string	ideas[100];
	protected:
	private:
};

#endif