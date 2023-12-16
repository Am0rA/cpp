/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/15 19:58:06 by itopchu       #+#    #+#                 */
/*   Updated: 2023/12/15 19:58:06 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename Container>
int	fillContainer(Container& container, int& ac, char **av)
{
	try
	{
		for (int i = 0; i < ac; i++)
		{
			int tmp = std::stoi(av[i]);
			if (tmp < 0)
				throw std::runtime_error("Error: Non positive value");
			container.push_back(std::stoi(av[i]));
		}
		return (0);
	}
	catch(const std::invalid_argument& e)
	{std::cerr << "Invalid argument: " << e.what() << std::endl;}
	catch(const std::out_of_range& e)
	{std::cerr << "Out of range: " << e.what() << std::endl;}
	catch(const std::exception& e)
	{std::cerr << e.what() << '\n';}
	return (1);
}

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

int main(int ac, char **av)
{
	if (ac < 2)
		return (1);
	ac--;
	av++;
	std::vector<int> vec;
	if (fillContainer(vec, ac, av))
		return (1);
	std::deque<int> que;
	if (fillContainer(que, ac, av))
		return (1);
	std::cout << "Before:	";
	for (auto element : vec)
		std::cout << element << " ";
	std::cout << "\n";

	double t1 = PmergeMe<std::vector<int>>::sort(vec);
	double t2 = PmergeMe<std::deque<int>>::sort(que);

	std::cout << "After:	";
	for (auto element : vec)
		std::cout << element << " ";
	std::cout << "\n";

	std::cout << std::fixed;
	std::cout << std::setprecision(getPrecision(t1)) << "Time to process a range of " << ac << " elements with std::vector<int>	: " << t1 << " us\n";
	std::cout << std::setprecision(getPrecision(t2)) << "Time to process a range of " << ac << " elements with std::deque<int>	: " << t2 << " us\n";
}
