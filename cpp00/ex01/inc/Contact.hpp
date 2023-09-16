/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 13:01:43 by itopchu       #+#    #+#                 */
/*   Updated: 2023/08/31 13:01:43 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

# include <sstream>
# include <iostream>
# include <cstdlib>
# define RED "\e[1;31m"
# define BLUE "\e[1;34m"
# define GREEN "\e[1;32m"
# define L_BLUE "\e[1;36m"
# define DEFCOLOR "\033[0m"

class Contact
{
	public:
		Contact();
		Contact(const Contact &copy);
		Contact(std::string FirstName, std::string LastName, std::string NickName, std::string PhoneNumber, std::string DarkestSecret);
		~Contact();
		Contact &	operator=(const Contact &assign);
		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickName() const;
		std::string getPhoneNumber() const;
		std::string getDarkestSecret() const;
		bool setFirstName();
		bool setLastName();
		bool setNickName();
		bool setPhoneNumber();
		bool setDarkestSecret();
	private:
		std::string _FirstName;
		std::string _LastName;
		std::string _NickName;
		std::string _PhoneNumber;
		std::string _DarkestSecret;
		int getInput(std::string &buf, int type, std::string &message);
};

bool isCompare(const std::string &str, int (*compare)(int));
#endif