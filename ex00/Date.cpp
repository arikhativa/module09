/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 13:17:17 by yrabby            #+#    #+#             */
/*   Updated: 2023/06/26 09:27:51 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Date.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Date::Date(unsigned int date)
	: _date(date)
{
	if (!_isValid())
		throw std::invalid_argument("Error: bad input => " + date);
}

Date::Date(const std::string &date)
	: _date(_stringToDate(date))
{
	if (!_isValid())
		throw std::invalid_argument("Error: bad input => " + date);
}

Date::Date( const Date & src )
	: _date(src.getDate())
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Date::~Date()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Date &				Date::operator=( Date const & rhs )
{
	if ( this != &rhs )
	{
		this->_date = rhs.getDate();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Date const & i )
{
	o << i.dateToString();
	return o;
}

bool Date::operator<(const Date &d) const
{
	return getDate() < d.getDate();
}

bool Date::operator>(const Date &d) const
{
	return getDate() > d.getDate();
}

bool Date::operator==(const Date &d) const
{
	return getDate() == d.getDate();
}

bool Date::operator!=(const Date &d) const
{
	return getDate() != d.getDate();
}


/*
** --------------------------------- METHODS ----------------------------------
*/

unsigned int	Date::getDate(void) const
{
	return _date;
}

std::string		Date::dateToString(void) const
{
	std::string year(_numToString(_getYear()));
	if (year.length() < 4)
		year = std::string(4 - year.length(), '0') + year;

	std::string month(_numToString(_getMonth()));
	if (month.length() < 2)
		month = std::string(2 - month.length(), '0') + month;

	std::string day(_numToString(_getDay()));
	if (day.length() < 2)
		day = std::string(2 - day.length(), '0') + day;

	return  year + "-" + month + "-" + day;
}

bool	Date::_isValid(void) const
{
	unsigned int day = _getDay();
	if (day < 1 || day > 31)
		return false;
	unsigned int month = _getMonth();
	if (month < 1 || month > 12)
		return false;
	unsigned int year = _getYear();
	if (year < 1)
		return false;

	bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	unsigned int daysInMonth[] = {31, 28 + static_cast<unsigned int>(isLeapYear), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
    return day <= daysInMonth[month - 1];
}

unsigned int	Date::_getDay(void) const
{
	return _date % 100;
}

unsigned int	Date::_getMonth(void) const
{
	return _date % 10000 / 100;
}

unsigned int	Date::_getYear(void) const
{
	return _date / 10000;
}

unsigned int	Date::_getDay(const std::string &date) const
{
	return std::atoi(date.substr(8, 10).c_str());
}

unsigned int	Date::_getMonth(const std::string &date) const
{
	return std::atoi(date.substr(5, 7).c_str());
}

unsigned int	Date::_getYear(const std::string &date) const
{
	return std::atoi(date.substr(0, 4).c_str());
}

bool	Date::_isValidChars(const std::string &date) const
{
	for (unsigned int i = 0; i < _STRING_LEN; i++)
	{
		if (i == 4 || i == 7)
		{
			if (date[i] != '-')
				return false;
		}
		else if (!std::isdigit(date[i]))
			return false;
	}
	return true;
}

bool	Date::_isStringValid(const std::string &date) const
{
	if (_STRING_LEN != date.length())
		return false;
	if (!_isValidChars(date))
		return false;
	return true;
}

unsigned int	Date::_stringToDate(const std::string &date) const
{
	if (!_isStringValid(date))
		throw std::invalid_argument("Error: bad input => " + date);
	return _getYear(date) * 10000 + _getMonth(date) * 100 + _getDay(date);
} 

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */