/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/20 22:31:08 by itopchu       #+#    #+#                 */
/*   Updated: 2023/09/20 22:31:08 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
# define MAIN_HPP
# define RED "\e[1;31m"
# define BLUE "\e[1;34m"
# define GREEN "\e[1;32m"
# define YELLOW "\e[0;33m"
# define PURP "\e[0;35m"
# define L_BLUE "\e[1;36m"
# define DEFCOLOR "\033[0m"
# include <iostream>

void	putMessage(const char* color, const std::string& message, int newline);

#endif
