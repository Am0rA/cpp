/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/29 21:04:14 by itopchu       #+#    #+#                 */
/*   Updated: 2023/10/29 21:04:14 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main(void)
{
	{
		std::cout << "--------------TEST FROM SUBJECT--------------" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "----Top----\n";
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "----Size----\n";
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		++it;
		--it;
		std::cout << "----Iterations----" << std::endl;
		while (it != mstack.end())
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);

	}
	std::cout << "--------------ADDITIONAL TEST CASE--------------" << std::endl;
	{
		std::cout << "----1----" << std::endl;
		// Test an empty MutantStack
		MutantStack<int> emptyStack;
		std::cout << "Size of empty stack: " << emptyStack.size() << std::endl;
		std::cout << "Iterator range: " << (emptyStack.begin() == emptyStack.end() ? "Empty" : "Not Empty") << std::endl;
	}

	{
		std::cout << "----2----" << std::endl;
		// Test MutantStack with one element
		MutantStack<int> singleElementStack;
		singleElementStack.push(42);
		std::cout << "Size of single-element stack: " << singleElementStack.size() << std::endl;
		std::cout << "Top of single-element stack: " << singleElementStack.top() << std::endl;

		MutantStack<int>::iterator it = singleElementStack.begin();
		std::cout << "Iterator value: " << *it << std::endl;
		++it;
		std::cout << "Iterator range: " << (it == singleElementStack.end() ? "Empty" : "Not Empty") << std::endl;
	}

	{
		std::cout << "----3----" << std::endl;
		// Test MutantStack with repeated elements
		MutantStack<int> repeatedElementStack;
		for (int i = 0; i < 5; ++i)
			repeatedElementStack.push(i * 645);

		std::cout << "Size of repeated-element stack: " << repeatedElementStack.size() << std::endl;

		int count = 0;
		for (MutantStack<int>::iterator it = repeatedElementStack.begin(); it != repeatedElementStack.end(); ++it)
		{
			std::cout << "Element at iterator: " << *it << std::endl;
			++count;
		}

		std::cout << "Total elements iterated: " << count << std::endl;
	}
	return (0);
}
