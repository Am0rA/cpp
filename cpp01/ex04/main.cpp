/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 13:04:20 by itopchu       #+#    #+#                 */
/*   Updated: 2023/08/31 13:04:20 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "expected: filename s1 s2" << std::endl;
		return (1);
	}
	std::string file = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];
	if (file == "" || s1 == "" || s2 == "")
	{
		std::cerr << "empty strings are not allowed" << std::endl;
		return (1);
	}
	std::ifstream inputFile(file.c_str());
	if (!inputFile)
	{
		std::cerr << "Error: Unable to open: " << file << std::endl;
		return (1);
	}
	std::string fileOut = file + ".replace";
	std::ofstream outputFile(fileOut.c_str());
	if (!inputFile)
	{
		inputFile.close();
		std::cerr << "Error: Unable to open: " << file + ".replace" << std::endl;
		return (1);
	}
	std::string line;
	while (std::getline(inputFile, line))
	{
		std::string newLine = "";
		size_t pos = 0;
		while (pos < line.length())
		{
			size_t found = line.find(s1, pos);
			if (found == std::string::npos)
			{
				newLine += line.substr(pos);
				break ;
			}
			newLine += line.substr(pos, found - pos) + s2;
			pos = found + s1.length();
		}
		outputFile << newLine << std::endl;
	}
	std::cout << "Text: \"" \
			<< GREEN << s1 << DEF << "\" in " \
			<< GREEN << file << DEF << " replaced with \"" \
			<< GREEN << s2 << DEF << "\" into " \
			<< GREEN << fileOut << DEF << std::endl;
	inputFile.close();
	outputFile.close();
	return (0);
}