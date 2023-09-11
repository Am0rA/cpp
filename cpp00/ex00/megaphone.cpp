/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   megaphone.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 12:53:42 by itopchu       #+#    #+#                 */
/*   Updated: 2023/08/31 12:53:42 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char** argv)
{
    if(argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
	{
        for(int i = 1; i < argc; ++i)
		{
            std::string str(argv[i]);
            for(char& c : str)
                c = std::toupper(static_cast<unsigned char>(c));
            std::cout << str;
        }
        std::cout << std::endl;
    }
    return 0;
}