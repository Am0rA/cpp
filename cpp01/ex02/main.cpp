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
	std::string text = "I am text";
	std::string	*textPTR = &text;
	std::string &textREF = text;

	std::cout << "address of text: " << &text << std::endl;
	std::cout << "address of textPTR: " << textPTR << std::endl;
	std::cout << "address of textREF: " << &textREF << std::endl;

	std::cout << "value of text: " << text << std::endl;
	std::cout << "value of textPTR: " << *textPTR << std::endl;
	std::cout << "value of textREF: " << textREF << std::endl;

	textREF = "reference is powerfull"; 

	std::cout << "address of text: " << &text << std::endl;
	std::cout << "address of textPTR: " << textPTR << std::endl;
	std::cout << "address of textREF: " << &textREF << std::endl;

	std::cout << "value of text: " << text << std::endl;
	std::cout << "value of textPTR: " << *textPTR << std::endl;
	std::cout << "value of textREF: " << textREF << std::endl;

	return (0);
}