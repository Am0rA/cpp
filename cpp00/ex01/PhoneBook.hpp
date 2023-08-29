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
		bool		isCompare(std::string str, int (*compare)(int));
		std::string	GetColumn(std::string str);
	
	private:
		Contact	_ContactList[8];
		int		_Index;
		int		_ContactNum;
};

#endif