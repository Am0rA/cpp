#ifndef PHONEBOOK_HPPP
#define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		int			AddContact();
		int			FindContact();
		int			SearchContact();
	private:
		std::string	GetColumn(std::string str);
		Contact	_ContactList[8];
		int		_Index;
		int		_ContactNum;
};

#endif