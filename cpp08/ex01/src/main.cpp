/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/25 20:58:31 by itopchu       #+#    #+#                 */
/*   Updated: 2023/10/25 20:58:31 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	{
		try {
			Span sp(8);
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);

			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;

			std::vector<int> moreNumbers;
			moreNumbers.push_back(8);
			moreNumbers.push_back(1);
			moreNumbers.push_back(22);
			sp.addNumbers(moreNumbers);

			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;

			Span sp2 = sp;
			Span sp3(3);
			sp3 = sp2;

		} catch (const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
	{
		try
		{
			Span sp(10000);

			std::vector<int> largeNumberVector;
			for (int i = 1; i <= 10000; ++i) {
				largeNumberVector.push_back(i);
			}
			sp.addNumbers(largeNumberVector);
			std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
			std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
		} catch (const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
    return 0;
}