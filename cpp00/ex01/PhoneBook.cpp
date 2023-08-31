/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 12:54:52 by itopchu       #+#    #+#                 */
/*   Updated: 2023/08/31 12:54:52 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	PhoneBook::AddContact()
{
    Contact newContact;
    if (!newContact.setFirstName() ||
		!newContact.setLastName() ||
        !newContact.setNickName() ||
		!newContact.setPhoneNumber() ||
        !newContact.setDarkestSecret())
		return (1);
	this->_Index++;
	if (this->_ContactNum < 8)
		this->_ContactNum++;
	if(this->_Index == 8)
		_Index = 0;
	this->_ContactList[this->_Index] = newContact;
	return (0);
}

int	PhoneBook::SearchContact()
{
	if (this->_ContactNum == 0)
	{
		std::cout << "No Contact saved in the Book\n";
		return (0);
	}
	std::cout << "\n     Index" << "|";
	std::cout << "First Name" << "|";
	std::cout << " Last Name" << "|";
	std::cout << " Nick Name" << "|\n";
	for (int i = 0; i < this->_ContactNum; i++)
	{
        std::stringstream index;
        index << i + 1;
		std::cout << this->GetColumn(index.str()) << "|";
		std::cout << this->GetColumn(this->_ContactList[i].getFirstName()) << "|";
		std::cout << this->GetColumn(this->_ContactList[i].getLastName()) << "|";
		std::cout << this->GetColumn(this->_ContactList[i].getNickName()) << "|\n";
	}
	return (this->FindContact());
}

std::string	PhoneBook::GetColumn(const std::string &str)
{
	std::string	column;

	if (str.length() > 10)
		column = str.substr(0, 9) + ".";
	else
	{
		column.resize(10, ' ');
		column.replace(10 - str.length(), str.length(), str);
	}
	return (column);
}

int	PhoneBook::FindContact()
{
	std::string line;
	int			index;
	while (1)
	{
		std::cout << BLUE << "Give index to see details: " << DEFCOLOR;
		std::getline(std::cin, line);
		if (std::cin.eof())
		{
			std::cout << "EOF received\n";
			return (1);
		}
		index = std::atoi(line.c_str());
		if (line.empty())
			std::cout << RED << "Empty input is not accepted\n" << DEFCOLOR;
		else if (isCompare(line, std::isdigit) == false)
			std::cout << RED << "Only numerical input is accepted\n"<< DEFCOLOR;
		else if (index > this->_ContactNum || index < 1)
			std::cout << RED << "Index is out of range\n" << DEFCOLOR;
		else
		{
			std::cout << "First Name: " << this->_ContactList[index - 1].getFirstName() << "\n";
			std::cout << "Last Name:" << this->_ContactList[index - 1].getLastName() << "\n";
			std::cout << "Nick Name: " << this->_ContactList[index - 1].getNickName() << "\n";
			std::cout << "Phone Number: " << this->_ContactList[index - 1].getPhoneNumber() << "\n";
			std::cout << "Secret: " << this->_ContactList[index - 1].getDarkestSecret() << "\n";
			break ;
		}
	}
	return (0);
}

PhoneBook::PhoneBook()
{
	this->_Index = -1;
	this->_ContactNum = 0;
}

PhoneBook::~PhoneBook()
{

}