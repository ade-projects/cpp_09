/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 08:35:17 by adeestev          #+#    #+#             */
/*   Updated: 2026/11/13 12:17:23 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <iostream>
# include <string>
# include <cstdlib>
# include <cctype>

class RPN
{
	private:
		std::stack<int> _stack;

	public:
		RPN();
		RPN(const RPN &src);
		RPN& operator=(const RPN &src);
		~RPN();

		void calculate(const std::string& expression);
};

#endif
