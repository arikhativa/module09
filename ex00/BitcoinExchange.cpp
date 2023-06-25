/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 14:01:18 by yrabby            #+#    #+#             */
/*   Updated: 2023/06/25 17:54:37 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

static void	validateRate(const std::string &rate)
{
	if (rate.find_first_not_of("0123456789.") != std::string::npos)
		throw std::invalid_argument("Invalid rate");
}

BitcoinExchange::BitcoinExchange(const std::string &file_name)
{
	std::fstream file;

	file.open(file_name.c_str(), std::ios::in);
	if (!file.is_open() || !file.good())
		throw std::invalid_argument("Failed to open file");

	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::string rate = line.substr(11, -1);
		try
		{
			Date d(line.substr(0, 10));
			validateRate(rate);
			_exchange_rate[d] = static_cast<float>(std::strtod(rate.c_str(), NULL));
		}
		catch (const std::exception &e)
		{
			std::cerr << "Failed to parse line: '" << line << "' Error: " << e.what() << std::endl;
		}
	}
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange & src )
	: _exchange_rate(src._exchange_rate)
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

BitcoinExchange::~BitcoinExchange()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

BitcoinExchange &				BitcoinExchange::operator=( BitcoinExchange const & rhs )
{
	if ( this != &rhs )
	{
		_exchange_rate = rhs._exchange_rate;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

float	BitcoinExchange::getExchangeRate(const Date &date) const
{
	std::map<const Date,float>::const_iterator it = _exchange_rate.lower_bound(date);

	if ((it == _exchange_rate.begin()) && (it->first != date))
		return -1;
	if (it == _exchange_rate.end())
		return -1;
	if ((it != _exchange_rate.begin()) && (it->first != date))
		it--;
	return it->second;
}


/* ************************************************************************** */