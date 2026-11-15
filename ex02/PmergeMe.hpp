/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 08:37:31 by adeestev          #+#    #+#             */
/*   Updated: 2026/11/14 14:26:35 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <iostream>
# include <string>
# include <cstdlib>
# include <cctype>
# include <utility>
# include <algorithm>
# include <sys/time.h>

class PmergeMe
{
	private:
		std::vector<int> _vector;
		std::deque<int> _deque;

		long sortVector(int ac, char **av);
		long sortDeque(int ac, char **av);
		int getJacobsthal(int n);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &src);
		PmergeMe& operator=(const PmergeMe &src);
		~PmergeMe();

		void sortAndDisplay(int ac, char **av);
};

#endif
