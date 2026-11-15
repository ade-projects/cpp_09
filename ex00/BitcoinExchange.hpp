/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 08:31:51 by adeestev          #+#    #+#             */
/*   Updated: 2026/11/10 18:20:36 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <iostream>
# include <string>
# include <fstream>
# include <sstream>
# include <cstdlib>
# include <cctype>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _database;
		bool _isValidDate(const std::string &date);
		
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange& operator=(const BitcoinExchange &src);
		~BitcoinExchange();
		
		void loadDatabase(const std::string &filename);
		void processInput(const std::string &filename);
};

#endif
 