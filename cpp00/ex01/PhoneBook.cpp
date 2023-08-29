#include "PhoneBook.hpp"

bool	PhoneBook::isCompare(std::string str, int (*compare)(int))
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if (compare(str[i])== 0)
			return (false);
	}
	return (true);
}

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
		std::cout << "No Contact saved in the Book" << std::endl;
		return (0);
	}
	std::cout << std::endl << "     Index" << "|";
	std::cout << "First Name" << "|";
	std::cout << " Last Name" << "|";
	std::cout << " Nick Name" << "|" << std::endl;
	for (int i = 0; i < this->_ContactNum; i++)
	{
        std::stringstream index;
        index << i + 1;
		std::cout << this->GetColumn(index.str()) << "|";
		std::cout << this->GetColumn(this->_ContactList[i].getFirstName()) << "|";
		std::cout << this->GetColumn(this->_ContactList[i].getLastName()) << "|";
		std::cout << this->GetColumn(this->_ContactList[i].getNickName()) << "|" << std::endl;
	}
	return (this->FindContact());
}

std::string	PhoneBook::GetColumn(std::string str)
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
			std::cout << "EOF received" << std::endl;
			return (1);
		}
		index = std::atoi(line.c_str());
		if (line.empty())
			std::cout << RED << "Empty input is not accepted" << DEFCOLOR << std::endl;
		else if (this->isCompare(line, std::isdigit) == false)
			std::cout << RED << "Only numerical input is accepted"<< DEFCOLOR << std::endl;
		else if (index > this->_ContactNum || index < 1)
			std::cout << RED << "Index is out of range" << DEFCOLOR << std::endl;
		else
		{
			std::cout << "First Name: " << this->_ContactList[index - 1].getFirstName() << std::endl;
			std::cout << "Last Name:" << this->_ContactList[index - 1].getLastName() << std::endl;
			std::cout << "Nick Name: " << this->_ContactList[index - 1].getNickName() << std::endl;
			std::cout << "Phone Number: " << this->_ContactList[index - 1].getPhoneNumber() << std::endl;
			std::cout << "Secret: " << this->_ContactList[index - 1].getDarkestSecret() << std::endl;
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