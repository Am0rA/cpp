/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/15 19:58:20 by itopchu       #+#    #+#                 */
/*   Updated: 2023/12/15 19:58:20 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
// Time calculation
# include <chrono>
// used containers
#include <vector>
#include <deque>
// to int
#include <string>
// output
#include <iostream>
// exception throwing
#include <stdexcept>
// std::setprecision
#include <iomanip>

template <typename Container> 
class PmergeMe
{
	public:
		static double	sort(Container& container);
		static void	sortVector(std::vector<int>& container);
		static void	sortDeque(std::deque<int>& container);
};

#endif