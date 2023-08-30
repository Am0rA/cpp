
#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phoneBook;
	std::string line;

	while (true)
	{
		std::cout << GREEN << "Enter a command " << L_BLUE << "(ADD, SEARCH, EXIT)" << DEFCOLOR << "\n";
		std::cout << BLUE << "Input: " << DEFCOLOR;
		if (!std::getline(std::cin, line) || line == "EXIT")
		{
			if (std::cin.eof())
				std::cout <<  "EOF received\n";
			std::cout << GREEN << "Book is put on the shelf.\n" << DEFCOLOR;
			break ;
		}
		else if (line == "ADD" && phoneBook.AddContact() == 1)
			return (0);
		else if (line == "SEARCH" && phoneBook.SearchContact() == 1)
				return (0);
		else
			std::cout << RED << "Invalid input, Please enter ADD, SEARCH or EXIT" << DEFCOLOR << "\n";
	}
	return (0);
}
