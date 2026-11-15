/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 08:33:14 by adeestev          #+#    #+#             */
/*   Updated: 2026/11/13 12:10:33 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &src)
{
	*this = src;
}

RPN& RPN::operator=(const RPN &src)
{
	if (this != &src)
	{
		this->_stack = src._stack;
	}
	return (*this);
}

RPN::~RPN() {}

void RPN::calculate(const std::string& expression)
{
	for (size_t i = 0; i < expression.length(); i++)
	{
		char c = expression[i];
		
		if (c == ' ')
		{
			continue ;
		}
		else if (isdigit(c))
		{
			_stack.push(c - '0');
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			if (_stack.size() < 2)
			{
				std::cerr << "Error" << std::endl;
				return ;
			}
			
			int val2 = _stack.top();
			_stack.pop();
			int val1 = _stack.top();
			_stack.pop();
		
			int result = 0;
			if (c == '+')
				result = val1 + val2;
			else if (c == '-')
				result = val1 - val2;
			else if (c == '*')
				result = val1 * val2;
			else if (c == '/')
			{
				if (val2 == 0)
				{
					std::cerr << "Error" << std::endl;
					return ;
				}
				result = val1 / val2;
			}
			_stack.push(result);
		}
		else
		{
			std::cerr << "Error" << std::endl;
			return ;
		}
	}

	if (_stack.size() == 1)
	{
		std::cout << _stack.top() << std::endl;
	}
	else
	{
		std::cerr << "Error" << std::endl;
	}
}