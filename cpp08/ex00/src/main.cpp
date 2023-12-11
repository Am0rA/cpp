/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/25 18:26:18 by itopchu       #+#    #+#                 */
/*   Updated: 2023/10/25 18:26:18 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

/*
1. `std::vector<T>` (Dynamic Array):
   - Dynamic array that can grow or shrink.
   - Fast random access to elements.
   - Efficient insertions and deletions at the end.
   - Order of elements preserved.
   - Use when dynamic sizing and efficient access are required.

2. `std::list<T>` (Doubly Linked List):
   - Doubly linked list for fast insertions and deletions at any position.
   - Slow random access.
   - Order of elements based on insertion order.
   - Use when efficient insertions at arbitrary positions are needed, and element order doesn't matter.

3. `std::set<T>` (Ordered Set):
   - Collection of unique, sorted elements.
   - Efficient searching and insertion.
   - Elements stored in sorted order.
   - Use for maintaining unique, sorted elements with efficient search and insertion.
*/

/*
replacing data type of second argument with auto makes it more flexiable*/

int main() {
	try {
		// Test with std::vector of integers
		std::vector<int> intVec = {1, 2, 3, 4, 5};
		int intValue = 3;
		std::vector<int>::iterator intResult = easyfind(intVec, intValue);
		std::cout << "Found in std::vector (integers): " << *intResult << std::endl;

		// Test with std::list of integers
		std::list<int> intList = {10, 20, 30, 40, 50};
		int intListValue = 20;
		std::list<int>::iterator intListResult = easyfind(intList, intListValue);
		std::cout << "Found in std::list (integers): " << *intListResult << std::endl;

		// Test with std::set of integers
		std::set<int> intSet = {100, 200, 300, 400, 500};
		int intSetValue = 300;
		std::set<int>::iterator intSetResult = easyfind(intSet, intSetValue);
		std::cout << "Found in std::set (integers): " << *intSetResult << std::endl;

		// Test with std::vector where element is not found
		int notFoundValue = 99;
		std::vector<int>::iterator notFoundResult = easyfind(intVec, notFoundValue);
		if (notFoundResult == intVec.end())
			std::cout << "notFoundResult is end of it" << std::endl;
		// This line should not be reached if NotFoundException is thrown
		std::cout << "Test 4: This line should not be reached.\n";
	} catch (const NotFoundException& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return 0;
}
