/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 14:01:18 by yrabby            #+#    #+#             */
/*   Updated: 2023/10/06 15:49:34 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

::size_t BitcoinExchange::_countChar(const std::string &str, char ch)
{
    ::size_t count = 0;
    for (size_t i = 0; i < str.length(); ++i)
    {
        if (str[i] == ch)
        {
            count++;
        }
    }
    return count;
}

void BitcoinExchange::_validateLine(const std::string &line)
{
    if (line.size() < 12)
    {
        throw std::invalid_argument("line too short: " + line);
    }
    if (line.find_first_not_of("0123456789-.,") != std::string::npos)
        throw std::invalid_argument("found bad char: " + line);
    if (_countChar(line, ',') != 1)
        throw std::invalid_argument("bad ',': " + line);
}

void BitcoinExchange::_validateRate(const std::string &rate)
{
    if (rate.find_first_not_of("0123456789.") != std::string::npos)
        throw std::invalid_argument("Invalid rate: " + rate);
    if (_countChar(rate, '.') > 1)
        throw std::invalid_argument("bad '.': " + rate);
    if (rate[0] == '.')
        throw std::invalid_argument("rate can't start with '.'");
}

static void validateFirstLine(const std::string &line)
{
    if (line != "date,exchange_rate")
        throw std::invalid_argument("Invalid first line");
}

BitcoinExchange::BitcoinExchange(const std::string &file_name)
{
    std::fstream file;

    file.open(file_name.c_str(), std::ios::in);
    if (!file.is_open() || !file.good())
        throw std::invalid_argument("Failed to open file");

    std::string line;
    std::getline(file, line);
    try
    {
        validateFirstLine(line);
        while (std::getline(file, line))
        {
            BitcoinExchange::_validateLine(line);
            std::string rate = line.substr(11, -1);
            _validateRate(rate);
            Date d(line.substr(0, 10));
            _exchange_rate[d] = static_cast<float>(std::strtod(rate.c_str(), NULL));
            if (_exchange_rate[d] < 0)
                throw std::invalid_argument("Invalid rate: " + rate);
        }
    }
    catch (const std::exception &e)
    {
        file.close();
        std::cerr << "Bad file: " << file_name << ". Error: " << e.what() << std::endl;
        throw e;
    }
    file.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) : _exchange_rate(src._exchange_rate)
{
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

BitcoinExchange::~BitcoinExchange()
{
    _exchange_rate.clear();
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
    if (this != &rhs)
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

float BitcoinExchange::getExchangeRate(const Date &date) const
{
    std::map<Date, float>::const_iterator it = _exchange_rate.lower_bound(date);

    if ((it == _exchange_rate.begin()) && (it->first != date))
        return -1;
    if (it == _exchange_rate.end())
        it--;
    if ((it != _exchange_rate.begin()) && (it->first != date))
        it--;
    return it->second;
}

/* ************************************************************************** */
