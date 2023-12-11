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

			std::cout << "Longest span case 1: " << sp.longestSpan() << std::endl;
			std::cout << "Shortest span case 1: " << sp.shortestSpan() << std::endl;

			sp.addNumbers(3);

			std::cout << "Longest span case 2: " << sp.longestSpan() << std::endl;
			std::cout << "Shortest span case 2: " << sp.shortestSpan() << std::endl;

			Span sp2 = sp;
			Span sp3(3);
			sp3 = sp2;

		} catch (const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
	{
		try {
			// Test Case 1: Empty Span
			Span emptySpan(5);
			std::cout << "Longest Span: " << emptySpan.longestSpan() << std::endl;
			std::cout << "Shortest Span: " << emptySpan.shortestSpan() << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}

		try {
			// Test Case 2: Span with a single element
			Span singleElementSpan(5);
			singleElementSpan.addNumber(42);
			std::cout << "Longest Span: " << singleElementSpan.longestSpan() << std::endl;
			std::cout << "Shortest Span: " << singleElementSpan.shortestSpan() << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}

		try {
			// Test Case 3: Span with normal size
			Span maxSizedSpan(50); // Maximum value for unsigned int
			// Add elements to fill the span
			maxSizedSpan.addNumbers(50);
			std::cout << "Longest Span: " << maxSizedSpan.longestSpan() << std::endl;
			std::cout << "Shortest Span: " << maxSizedSpan.shortestSpan() << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}

		try {
			// Test Case 4: Span with maximum allowed size
			Span maxSizedSpan(UINT_MAX); // Maximum value for unsigned int
			// Add elements to fill the span
			maxSizedSpan.addNumbers(UINT_MAX);
			std::cout << "Longest Span: " << maxSizedSpan.longestSpan() << std::endl;
			std::cout << "Shortest Span: " << maxSizedSpan.shortestSpan() << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}

		try {
			// Test Case 5: Adding more elements than maxSize
			Span overflowSpan(5);
			std::multiset<int> overflowNumbers; // 10 elements
			for (int i = 0; i < 10; ++i)
				overflowNumbers.insert(42 * i);
			overflowSpan.addNumbers(overflowNumbers); // Should throw NoSpaceException
		} catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
    return 0;
}
