/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/13 19:22:17 by itopchu       #+#    #+#                 */
/*   Updated: 2023/12/13 19:22:17 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	getPrecision(double val)
{
	std::string valStr = std::to_string(val);
	size_t decimalPos = valStr.find('.');
	if (decimalPos != std::string::npos)
	{
		size_t nonZeroPos = valStr.find_last_not_of('0');
		return (nonZeroPos == std::string::npos) ? 0 : (nonZeroPos - decimalPos);
	}
	return 0;
}

void	writeCalculation(BitcoinExchange& data, BitcoinExchange& input)
{
	double result = data.getVal() * input.getVal();
	std::cout << input << " => " << std::fixed << std::setprecision(getPrecision(input.getVal())) << input.getVal() << " = " << std::setprecision(getPrecision(result)) << result << "\n";
}

void	convertInput(std::list<BitcoinExchange>& data, std::list<BitcoinExchange>& input)
{
	std::_List_iterator<BitcoinExchange>	tmp;
	for (auto node : input)
	{
		if (node.getStatus().empty())
		{
			tmp = data.begin();
			for (auto it = data.begin(); it != data.end(); ++it)
			{
				if (*it <= node && *tmp < *it)
					tmp = it;
			}
			if (*tmp > node)
				std::cout << "Error: No valid lower or equal data found\n";
			else
				writeCalculation(*tmp, node);
		}
		else
			std::cout << "Error: " + node.getStatus() << "\n";
	}
}

int	main(int ac, char **av)
{
	std::list<BitcoinExchange> input;
	std::list<BitcoinExchange> data;

	// Argument check
	if (ac != 2)
		throw std::invalid_argument("Usage: ./btc input.csv");

	// Openning data file
	std::ifstream dataFile("data.csv");
	if (!dataFile.is_open())
		throw std::runtime_error("Error opening the data file");
	std::string	line;

	// Header check for data file
	std::getline(dataFile, line);
	if (line != "date,exchange_rate")
	{
		std::cerr << "Wrong data.csv header" << std::endl;
		return (1);
	}
	// Reading data file into 'List data'
	while (std::getline(dataFile, line))
	{
		BitcoinExchange tmp(line, ',');
		// Discard faulty data lines
		if (tmp.getStatus().empty())
		{
			// Sort data dates
			std::list<BitcoinExchange>::iterator it = data.begin();
			while (it != data.end())
			{
				if (*it > tmp)
					break ;
				it++;
			}
			data.insert(it, tmp);
		}
		else
			std::cerr << "Bad input in data: " << tmp.getStatus() << std::endl;
	}
	dataFile.close();
	if (data.empty())
	{
		std::cerr << "Empty data" << std::endl;
		return (1);
	}

	// Openning input file
	std::ifstream inputFile(av[1]);
	if (!inputFile.is_open())
		throw std::runtime_error("Error opening the input file");
	// Header check for input file
	std::getline(inputFile, line);
	if (line != "date | value\r")
	{
		std::cerr << "Wrong input header" << std::endl;
		return (1);
	}
	// Reading input file into 'List input'
	while (std::getline(inputFile, line))
	{
		BitcoinExchange tmp(line, '|');
		input.push_back(tmp);
	}
	inputFile.close();
	if (input.empty())
	{
		std::cerr << "Empty input" << std::endl;
		return (1);
	}

	// Output part
	convertInput(data, input);
	return (0);
}