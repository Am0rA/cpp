/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/13 16:18:00 by itopchu       #+#    #+#                 */
/*   Updated: 2023/12/13 16:18:00 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <queue>
#include <cctype>
#include <string>
#include <iostream>
#include <stdexcept>

int main(int ac, char **av)
{
	if (ac != 2)
		throw std::invalid_argument("Usage: ./RPN \"[...]\"");

	std::queue<int> nums;
	std::queue<char> symbols;

	for (int i = 0; av[1][i]; i++) {
		if (std::isdigit(av[1][i]))
			nums.push(av[1][i] - '0');
		else if (av[1][i] != ' ') {
			symbols.push(av[1][i]);
			if (symbols.front() != '/' && symbols.front() != '*' &&
				symbols.front() != '+' && symbols.front() != '-')
				throw std::invalid_argument("Non valid character");
		}
	}

	if (nums.empty())
		throw std::invalid_argument("No digit found");

	double val = nums.front();
	nums.pop();

	while (!nums.empty()) {
		if (symbols.empty())
			throw std::invalid_argument("Missing operator");

		switch (symbols.front()) {
			case '*':
				val *= nums.front();
				break;
			case '/':
				val /= nums.front();
				break;
			case '-':
				val -= nums.front();
				break;
			default:
				val += nums.front();
				break;
		}

		symbols.pop();
		nums.pop();
	}

	if (!symbols.empty())
		throw std::invalid_argument("Missing digit");

	std::cout << val << std::endl;
	return 0;
}