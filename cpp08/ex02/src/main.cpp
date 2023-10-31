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
		std::cout << mstack.top() << std::endl;
		// std::cout << mstack. << std::endl;
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
		std::cout << "--------------ADDITIONAL TEST CASE--------------" << std::endl;
		std::list<int> mstack;
		// mstack.push(5);
		// mstack.push(17);
		mstack.push_back(5);
		mstack.push_back(17);
		// std::cout << mstack.top() << std::endl;
		std::cout << mstack.back() << std::endl;
		// mstack.pop();
		mstack.pop_back();
		std::cout << mstack.size() << "	(size of std::list)" << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		mstack.push_back(0);
		std::cout << std::endl;
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	return (0);
}
