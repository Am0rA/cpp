/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 13:01:35 by itopchu       #+#    #+#                 */
/*   Updated: 2023/08/31 13:01:35 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
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
		std::string	GetColumn(const std::string &str);
		Contact	_ContactList[8];
		int		_Index;
		int		_ContactNum;
};

#endif