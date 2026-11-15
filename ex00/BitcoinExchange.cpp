/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 08:31:33 by adeestev          #+#    #+#             */
/*   Updated: 2026/11/11 11:07:55 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	*this = src; 
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &src)
{
	if (this != &src)
	{
		this->_database = src._database;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::_isValidDate(const std::string &date)
{
	if (date.length() != 10)
	{
		return (false);
	}
	if (date[4] != '-' || date[7] != '-')
	{
		return (false);
	}
	for (int i = 0; i < 10; i++)
	{
		if (i != 4 && i != 7)
		{
			if (!isdigit(date[i]))
			{
				return (false);
			}
		}
	}
	std::string yearStr = date.substr(0, 4);
	std::string monthStr = date.substr(5, 2);
	std::string dayStr = date.substr(8, 2);

	int year;
	int month;
	int day;

	std::istringstream ssYear(yearStr);
	ssYear >> year;
	std::istringstream ssMonth(monthStr);
	ssMonth >> month;
	std::istringstream ssDay(dayStr);
	ssDay >> day;

	if (month < 1 || month > 12 || day < 1 || day > 31)
	{
		return (false);
	}

	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (month == 2)
	{
		bool isLeapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
		if (isLeapYear && day > 29)
		{
			return (false);
		}
		if (!isLeapYear && day > 28)
		{
			return (false);
		}
	}
	else
	{
		if (day > daysInMonth[month - 1])
		{
			return (false);
		}
	}

	return (true);
}

void BitcoinExchange::loadDatabase(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cout << "Error: database file can't be opened." << std::endl;
		return ;
	}
	std::string line;
	std::getline(file, line);

	while (std::getline(file, line))
	{
		size_t commaPos = line.find(',');
		if (commaPos != std::string::npos)
		{
			std::string date = line.substr(0, commaPos);
			std::string exchangeRate = line.substr(commaPos + 1);
			float rate;
			std::istringstream ss(exchangeRate);
			ss >> rate;

			_database[date] = rate;
		}
	}
}

void BitcoinExchange::processInput(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cout << "Error: file can't be opened." << std::endl;
		return ;
	}
	std::string line;
	std::getline(file, line);

	while (std::getline(file, line))
	{
		size_t pipePos = line.find(" | ");
		if (pipePos == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue ;
		}
		std::string date = line.substr(0, pipePos);
		std::string	valueString = line.substr(pipePos + 3);
	
		if (!_isValidDate(date))
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue ;
		}
		
		float value;
		std::istringstream ss(valueString);
		ss >> value;

		if (value < 0)
		{
			std::cout << "Error: not a positive number." << std::endl;
			continue ;
		}
		else if (value > 1000)
		{
			std::cout << "Error: too large a number." << std::endl;
			continue ;
		}
		
		std::map<std::string, float>::iterator it = _database.lower_bound(date);

		if (it == _database.begin() && it->first != date)
		{
			std::cout << "Error: date not found in database (too early)." << std::endl;
			continue ;
		}

		if (it == _database.end() || it->first != date)
		{
			--it;
		}

		std::cout << date << " => " << value << " = " << (value * it->second) << std::endl;
	}
}
