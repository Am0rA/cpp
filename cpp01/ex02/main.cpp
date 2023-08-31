/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 13:01:13 by itopchu       #+#    #+#                 */
/*   Updated: 2023/08/31 13:01:13 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string text = "HI THIS IS BRAIN";
	std::string	*textPTR = &text;
	std::string &textREF = text;

	std::cout << "address of text: " << &text << std::endl;
	std::cout << "address of textPTR: " << textPTR << std::endl;
	std::cout << "address of textREF: " << &textREF << std::endl;

	std::cout << "value of text: " << text << std::endl;
	std::cout << "value of textPTR: " << *textPTR << std::endl;
	std::cout << "value of textREF: " << textREF << std::endl;

	std::cout << "address of text: " << &text << std::endl;
	std::cout << "address of textPTR: " << textPTR << std::endl;
	std::cout << "address of textREF: " << &textREF << std::endl;

	std::cout << "value of text: " << text << std::endl;
	std::cout << "value of textPTR: " << *textPTR << std::endl;
	std::cout << "value of textREF: " << textREF << std::endl;
}