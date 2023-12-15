/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/14 00:27:10 by itopchu       #+#    #+#                 */
/*   Updated: 2023/12/14 00:27:10 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

// std::cout
# include <iostream>
// Used container type
# include <list>
// file stream for file reads
# include <fstream>
// std::tm
# include <iomanip>

class BitcoinExchange
{
	private:
		std::tm	timeStruct;
		double	val;
		std::string	line;
		std::string status;
		void	parseInput(char sign);
	public:
		BitcoinExchange(const std::string& line, char input);
		BitcoinExchange(void);
		virtual ~BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange& copy);
		const double&	getVal(void) const;
		const std::string&	getStatus(void) const;
		const std::tm&	getTime(void) const;
		const std::string& getLine(void) const;

		BitcoinExchange& operator=(const BitcoinExchange& assign);
		bool operator>(BitcoinExchange const &ref) const;
		bool operator<(BitcoinExchange const &ref) const;
		bool operator==(BitcoinExchange const &ref) const;
		bool operator>=(BitcoinExchange const &ref) const;
		bool operator<=(BitcoinExchange const &ref) const;
		friend std::ostream& operator<<(std::ostream& os, const BitcoinExchange& exchange);

};

#endif