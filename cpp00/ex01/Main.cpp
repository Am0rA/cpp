
#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phoneBook;
	std::string line;

	while (true)
	{
		if (!std::cin.eof())
		{
			std::cout << GREEN << "Enter a command " << L_BLUE << "(ADD, SEARCH, EXIT)" << DEFCOLOR << std::endl;
			std::cout << BLUE << "Input: " << DEFCOLOR;
			std::getline(std::cin, line);
		}
		if (line == "EXIT" || std::cin.eof())
		{
			std::cout << std::endl << GREEN << "Book is put on the shelf." << DEFCOLOR << std::endl;
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
		else
			std::cout << RED << "Invalid input, Please enter ADD, SEARCH or EXIT" << DEFCOLOR << std::endl;
	}
	return (0);
}
