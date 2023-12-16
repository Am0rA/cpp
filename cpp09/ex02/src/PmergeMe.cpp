/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/15 22:21:50 by itopchu       #+#    #+#                 */
/*   Updated: 2023/12/15 22:21:50 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template double PmergeMe<std::vector<int>>::sort(std::vector<int>&);
template double PmergeMe<std::deque<int>>::sort(std::deque<int>&);

template <typename Container>
double	PmergeMe<Container>::sort(Container& container)
{
	if (container.size() < 1)
		throw std::runtime_error("Empty container detected");
	auto start = std::chrono::high_resolution_clock::now();
	if constexpr (std::is_same_v<Container, std::vector<int>>)
		sortVector(container);
	else if (std::is_same_v<Container, std::deque<int>>)
		sortDeque(container);
	else
		throw std::runtime_error("Unexpected container");
	auto end = std::chrono::high_resolution_clock::now();
	double nano = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() / 1000.0;
	return (nano);
}

void	diveVector(std::vector<int>& s)
{
	if (s.size() == 2)
	{
		if (s[0] > s[1])
			std::swap(s[0], s[1]);
		return ;
	}
	else if (s.size() == 1)
		return ;
	size_t	half = s.size() / 2;
	std::vector<int> left(s.begin(), s.begin() + half);
	std::vector<int> right(s.begin() + half, s.end());
	diveVector(left);
	diveVector(right);
	size_t i = 0, j = 0, k = 0;
	while (i < left.size() && j < right.size())
	{
		if (left[i] <= right[j])
		{
			s[k] = left[i];
			++i;
		}
		else
		{
			s[k] = right[j];
			++j;
		}
		++k;
	}
	while (i < left.size())
	{
		s[k] = left[i];
		++i;
		++k;
	}
	while (j < right.size())
	{
		s[k] = right[j];
		++j;
		++k;
	}
}

void	diveDeque(std::deque<int>& s)
{
	if (s.size() == 2)
	{
		if (s[0] > s[1])
			std::swap(s[0], s[1]);
		return ;
	}
	else if (s.size() == 1)
		return ;
	size_t	half = s.size() / 2;
	std::deque<int> left(s.begin(), s.begin() + half);
	std::deque<int> right(s.begin() + half, s.end());
	diveDeque(left);
	diveDeque(right);
	size_t i = 0, j = 0, k = 0;
	while (i < left.size() && j < right.size())
	{
		if (left[i] <= right[j])
		{
			s[k] = left[i];
			++i;
		}
		else
		{
			s[k] = right[j];
			++j;
		}
		++k;
	}
	while (i < left.size())
	{
		s[k] = left[i];
		++i;
		++k;
	}
	while (j < right.size())
	{
		s[k] = right[j];
		++j;
		++k;
	}
}

template <typename Container>
void	PmergeMe<Container>::sortVector(std::vector<int>& container)
{
	std::vector<int> sorted = container;
	diveVector(sorted);
	container = sorted;
}

template <typename Container>
void	PmergeMe<Container>::sortDeque(std::deque<int>& container)
{
	std::deque<int>	sorted = container;
	diveDeque(sorted);
	container = sorted;
}
