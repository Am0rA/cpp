/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 12:54:41 by itopchu       #+#    #+#                 */
/*   Updated: 2023/08/31 12:54:41 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phoneBook;
	std::string line;

	while (true)
	{
		std::cout << GREEN << "Enter a command " << L_BLUE << "(ADD, SEARCH, EXIT)\n" << DEFCOLOR;
		std::cout << BLUE << "Input: " << DEFCOLOR;
		if (!std::getline(std::cin, line) || line == "EXIT")
		{
			if (std::cin.eof())
				std::cout << "EOF received\n";
			break ;
		}
		else if (line == "ADD")
		{
			if (phoneBook.AddContact() == 1)
				return (0);
		}
		else if (line == "SEARCH")
		{
			if (phoneBook.SearchContact() == 1)
				return (0);
		}
		else if (line.empty())
			std::cout << RED "Empty input is not accepted\n" DEFCOLOR;
		else
			std::cout << RED "Invalid input, Please enter ADD, SEARCH or EXIT\n" DEFCOLOR;
	}
	std::cout << GREEN << "Book is put on the shelf.\n" << DEFCOLOR;
	return (0);
}
