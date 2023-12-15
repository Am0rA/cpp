/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/14 00:56:48 by itopchu       #+#    #+#                 */
/*   Updated: 2023/12/14 00:56:48 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string& line, char input)
{
	this->line = line;
	parseInput(input);
}

BitcoinExchange::BitcoinExchange(void) :
	timeStruct(std::tm{}),
	val(0),
	line(""),
	status("empty")
{

}

BitcoinExchange::~BitcoinExchange(void)
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy) :
	timeStruct(copy.timeStruct),
	val(copy.val),
	line(copy.line),
	status(copy.status)
{

}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& assign)
{
	timeStruct = assign.timeStruct;
	val = assign.val;
	line = assign.line;
	status = assign.status;
	return (*this);
}

void	BitcoinExchange::parseInput(char sign)
{
	std::string	token;
	std::istringstream iss(line);
	if (std::getline(iss, token, sign))
	{
		std::istringstream dateStream(token);
		dateStream >> std::get_time(&timeStruct, "%Y-%m-%d");
		if (dateStream.fail())
			status = "bad input";
		std::getline(iss, token);
		if (token.front() == ' ')
			token.erase(0, 1);
		size_t lastNonSpace = token.find_last_not_of(" \t\n\r\f\v");
		if (lastNonSpace != std::string::npos)
			token.erase(lastNonSpace + 1);
		try
		{
			size_t pos;
			val = std::stod(token, &pos);
			if (pos < token.size())
				status = "bad input => " + line;
			if (val < 0)
				status = "not a positive number.";
		}
		catch (const std::invalid_argument& e)
		{ status = "bad input => " + line; }
		catch (const std::out_of_range& e)
		{ status = "too large a number."; }
		if (val >= 1000 && sign == '|')
			status = "too large a number.";
	}
	else
		status = "bad input";
}

const std::string&	BitcoinExchange::getStatus(void) const
{
	return (status);
}

const double&	BitcoinExchange::getVal(void) const
{
	return (val);
}

const std::tm&	BitcoinExchange::getTime(void) const
{
	return (timeStruct);
}

bool BitcoinExchange::operator>(BitcoinExchange const &ref) const
{
	if (timeStruct.tm_year < ref.timeStruct.tm_year)
		return false;
	else if (timeStruct.tm_year > ref.timeStruct.tm_year)
		return (true);
	if (timeStruct.tm_mon < ref.timeStruct.tm_mon)
		return false;
	else if (timeStruct.tm_mon > ref.timeStruct.tm_mon)
		return (true);
	if (timeStruct.tm_mday < ref.timeStruct.tm_mday)
		return false;
	else if (timeStruct.tm_mday > ref.timeStruct.tm_mday)
		return (true);
	return true;
}

bool BitcoinExchange::operator<(BitcoinExchange const &ref) const
{
	if (timeStruct.tm_year > ref.timeStruct.tm_year)
		return false;
	else if (timeStruct.tm_year < ref.timeStruct.tm_year)
		return true;
	if (timeStruct.tm_mon > ref.timeStruct.tm_mon)
		return false;
	else if (timeStruct.tm_mon < ref.timeStruct.tm_mon)
		return true;
	if (timeStruct.tm_mday > ref.timeStruct.tm_mday)
		return false;
	else if (timeStruct.tm_mday < ref.timeStruct.tm_mday)
		return true;
	return true;
}

bool BitcoinExchange::operator==(BitcoinExchange const &ref) const
{
	if (timeStruct.tm_year == ref.timeStruct.tm_year
	&& timeStruct.tm_mon == ref.timeStruct.tm_mon
	&& timeStruct.tm_mday == ref.timeStruct.tm_mday)
		return (true);
	return (false);
}

bool BitcoinExchange::operator<=(BitcoinExchange const &ref) const
{
    return !(ref < *this);
}

bool BitcoinExchange::operator>=(BitcoinExchange const &ref) const
{
    return !(*this < ref);
}

std::ostream& operator<<(std::ostream& os, const BitcoinExchange& exchange)
{
	std::tm tmp = exchange.getTime();
    os << std::setw(4) << std::setfill('0') << tmp.tm_year + 1900
       << "-" << std::setw(2) << std::setfill('0') << tmp.tm_mon + 1
       << "-" << std::setw(2) << std::setfill('0') << tmp.tm_mday;
    return os;
}