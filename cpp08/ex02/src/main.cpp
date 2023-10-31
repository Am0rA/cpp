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

int main(void)
{
	{
		std::cout << "--------------TEST FROM SUBJECT--------------" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << "	(size of MutantStack)" << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		std::cout << std::endl;
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	{
		std::cout << "--------------ADDITIONAL TEST CASES--------------" << std::endl;
		MutantStack<double> doubleStack;
		doubleStack.push(3.14);
		doubleStack.push(2.71);
		doubleStack.push(1.618);
		std::cout << "Top of doubleStack: " << doubleStack.top() << std::endl;
		doubleStack.pop();
		std::cout << "Size of doubleStack: " << doubleStack.size() << std::endl;

		MutantStack<std::string> stringStack;
		stringStack.push("Hello");
		stringStack.push("World");
		stringStack.push("C++");
		std::cout << std::endl;
		MutantStack<std::string>::iterator strIt = stringStack.begin();
		MutantStack<std::string>::iterator strIte = stringStack.end();
		while (strIt != strIte)
		{
			std::cout << *strIt << " ";
			++strIt;
		}
		std::cout << std::endl;
	}
	return (0);
}
