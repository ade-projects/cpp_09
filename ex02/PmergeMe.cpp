/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 08:37:21 by adeestev          #+#    #+#             */
/*   Updated: 2026/11/14 14:28:48 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src)
{
	*this = src;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &src)
{
	if (this != &src)
	{
		this->_vector = src._vector;
		this->_deque = src._deque;
	}
	return (*this);
}

PmergeMe::~PmergeMe() {}

int PmergeMe::getJacobsthal(int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	int prev2 = 0;
	int prev1 = 1;
	int curr = 0;
	for (int i = 2; i <= n; i++)
	{
		curr = prev1 + 2 * prev2;
		prev2 = prev1;
		prev1 = curr;
	}
	return (curr);
}

long PmergeMe::sortVector(int ac, char **av)
{
	struct timeval start, end;
	gettimeofday(&start, NULL);

	for (int i = 1; i < ac; i++)
	{
		_vector.push_back(std::atoi(av[i]));
	}

	std::vector< std::pair<int, int> > pairs;
	int straggler = -1;
	bool hasStraggler = false;

	if (_vector.size() % 2 != 0)
	{
		hasStraggler = true;
		straggler = _vector[_vector.size() - 1];
	}

	size_t limit = hasStraggler ? _vector.size() - 1 : _vector.size();
	for (size_t i = 0; i < limit; i += 2)
	{
		if (_vector[i] > _vector[i + 1])
		{
			pairs.push_back(std::make_pair(_vector[i], _vector[i + 1]));
		}
		else
		{
			pairs.push_back(std::make_pair(_vector[i + 1], _vector[i]));
		}
	}

	std::sort(pairs.begin(), pairs.end());

	std::vector<int> mainChain;
	if (!pairs.empty())
	{
		for (size_t i = 0; i < pairs.size(); i++)
		{
			mainChain.push_back(pairs[i].first);
		}
		mainChain.insert(mainChain.begin(), pairs[0].second);
		
		int jacobIndex = 3;
		size_t prevJacob = 1;

		while (prevJacob < pairs.size())
		{
			size_t currJacob = getJacobsthal(jacobIndex);
			if (currJacob > pairs.size())
			{
				currJacob = pairs.size();
			}
			for (size_t i = currJacob; i > prevJacob; i--)
			{
				int loser = pairs[i - 1].second;
				std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), loser);
				mainChain.insert(it, loser);
			}
			prevJacob = currJacob;
			jacobIndex++;
		}
	}

	if (hasStraggler)
	{
		std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
		mainChain.insert(it, straggler);
	}

	_vector = mainChain;

	gettimeofday(&end, NULL);
	return (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
}

long PmergeMe::sortDeque(int ac, char **av)
{
	struct timeval start, end;
	gettimeofday(&start, NULL);

	for (int i = 1; i < ac; i++)
	{
		_deque.push_back(std::atoi(av[i]));
	}

	std::deque< std::pair<int, int> > pairs;
	int straggler = -1;
	bool hasStraggler = false;

	if (_deque.size() % 2 != 0)
	{
		hasStraggler = true;
		straggler = _deque[_deque.size() - 1];
	}

	size_t limit = hasStraggler ? _deque.size() - 1 : _deque.size();
	for (size_t i = 0; i < limit; i += 2)
	{
		if (_deque[i] > _deque[i + 1])
		{
			pairs.push_back(std::make_pair(_deque[i], _deque[i + 1]));
		}
		else
		{
			pairs.push_back(std::make_pair(_deque[i + 1], _deque[i]));
		}
	}

	std::sort(pairs.begin(), pairs.end());

	std::deque<int> mainChain;
	if (!pairs.empty())
	{
		for (size_t i = 0; i < pairs.size(); i++)
		{
			mainChain.push_back(pairs[i].first);
		}
		mainChain.insert(mainChain.begin(), pairs[0].second);
		
		int jacobIndex = 3;
		size_t prevJacob = 1;

		while (prevJacob < pairs.size())
		{
			size_t currJacob = getJacobsthal(jacobIndex);
			if (currJacob > pairs.size())
			{
				currJacob = pairs.size();
			}
			for (size_t i = currJacob; i > prevJacob; i--)
			{
				int loser = pairs[i - 1].second;
				std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), loser);
				mainChain.insert(it, loser);
			}
			prevJacob = currJacob;
			jacobIndex++;
		}
	}

	if (hasStraggler)
	{
		std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
		mainChain.insert(it, straggler);
	}

	_deque = mainChain;

	gettimeofday(&end, NULL);
	return (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
}

void PmergeMe::sortAndDisplay(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
	{
		std::string arg = av[i];

		if (arg.empty())
		{
			std::cerr << "Error" << std::endl;
			return ;
		}
		
		for (size_t j = 0; j < arg.length(); j++)
		{
			if (!isdigit(arg[j]))
			{
				std::cerr << "Error" << std::endl;
				return ;
			}
		}
	}

	std::cout << "Before: ";
	for (int i = 1; i < ac; i++)
	{
		std::cout << av[i] << " ";
	}
	std::cout << std::endl;

	long time_vec = sortVector(ac, av);
	long time_deq = sortDeque(ac, av);

	std::cout << "After : ";
	for (size_t i = 0; i < _vector.size(); i++)
	{
		std::cout << _vector[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : " << time_vec << " us" << std::endl;
	std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque : " << time_deq << " us" << std::endl;
}
