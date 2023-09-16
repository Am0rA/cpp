/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 12:53:58 by itopchu       #+#    #+#                 */
/*   Updated: 2023/08/31 12:53:58 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	_FirstName = "NAME";
	_LastName = "LASTNAME";
	_NickName = "NICK";
	_PhoneNumber = "0000000000";
	_DarkestSecret = "SECRET";
}

Contact::Contact(const Contact &copy)
{
	_FirstName = copy.getFirstName();
	_LastName = copy.getLastName();
	_NickName = copy.getNickName();
	_PhoneNumber = copy.getPhoneNumber();
	_DarkestSecret = copy.getDarkestSecret();
}

Contact::Contact(std::string FirstName, std::string LastName, std::string NickName, std::string PhoneNumber, std::string DarkestSecret)
{
	_FirstName = FirstName;
	_LastName = LastName;
	_NickName = NickName;
	_PhoneNumber = PhoneNumber;
	_DarkestSecret = DarkestSecret;
}


Contact::~Contact()
{
	
}

int Contact::getInput(std::string &buf, int type, std::string &message)
{
	while (1)
	{
		std::cout << message;
		if (!std::getline(std::cin >> std::ws, buf))
		{
			if (std::cin.eof())
			{
				std::cout << "EOF received\n";
				return (0);
			}
		}
		if (buf.empty())
			std::cout << RED "Empty input is not accepted.\n" DEFCOLOR;
		else if (type == 0 && isCompare(buf, isalpha) == false)
			std::cout << RED "Non alpha input is not accepted\n" DEFCOLOR;
		else if (type == 1 && isCompare(buf, isdigit) == false)
			std::cout << RED "Non digit input is not accepted\n" DEFCOLOR;
		else
			break ;
	}
	return (1);
}

bool	isCompare(const std::string &str, int (*compare)(int))
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if (compare(str[i])== 0)
			return (false);
	}
	return (true);
}

Contact & Contact::operator=(const Contact &assign)
{
	_FirstName = assign.getFirstName();
	_LastName = assign.getLastName();
	_NickName = assign.getNickName();
	_PhoneNumber = assign.getPhoneNumber();
	_DarkestSecret = assign.getDarkestSecret();
	return *this;
}


std::string Contact::getFirstName() const
{
	return _FirstName;
}

bool Contact::setFirstName()
{
	std::string message = BLUE;
	message += "First Name: ";
	message += DEFCOLOR;
	return (getInput(this->_FirstName, 0, message));
}

std::string Contact::getLastName() const
{
	return _LastName;
}
bool Contact::setLastName()
{
	std::string message = BLUE;
	message += "Last Name: ";
	message += DEFCOLOR;
	return (getInput(this->_LastName, 0, message));
}

std::string Contact::getNickName() const
{
	return _NickName;
}
bool Contact::setNickName()
{
	std::string message = BLUE;
	message += "Nick Name: ";
	message += DEFCOLOR;
	return (getInput(this->_NickName, 0, message));
}

std::string Contact::getPhoneNumber() const
{
	return _PhoneNumber;
}
bool Contact::setPhoneNumber()
{
	std::string message = BLUE;
	message += "Phone Number: ";
	message += DEFCOLOR;
	return (getInput(this->_PhoneNumber, 1, message));
}

std::string Contact::getDarkestSecret() const
{
	return _DarkestSecret;
}
bool Contact::setDarkestSecret()
{
	std::string message = BLUE;
	message += "Darkest Secret: ";
	message += DEFCOLOR;
	return (getInput(this->_DarkestSecret, 2, message));
}
