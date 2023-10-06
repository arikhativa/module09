/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 12:54:42 by yrabby            #+#    #+#             */
/*   Updated: 2023/10/06 15:21:38 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATE_HPP
#define DATE_HPP

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

#include "numToString.hpp"

class Date
{
  public:
    explicit Date(const std::string &date);
    explicit Date(unsigned int date);
    Date(Date const &src);
    ~Date();

    Date &operator=(Date const &rhs);

    unsigned int getDate(void) const;
    std::string dateToString(void) const;

    bool operator<(const Date &d) const;
    bool operator>(const Date &d) const;
    bool operator==(const Date &d) const;
    bool operator!=(const Date &d) const;

  private:
    static const unsigned int _STRING_LEN = 10;

    unsigned int _date;

    // is()
    bool _isValid(void) const;
    bool _isStringValid(const std::string &date) const;
    bool _isValidChars(const std::string &date) const;

    // get()
    unsigned int _getDay(void) const;
    unsigned int _getMonth(void) const;
    unsigned int _getYear(void) const;
    unsigned int _getDay(const std::string &date) const;
    unsigned int _getMonth(const std::string &date) const;
    unsigned int _getYear(const std::string &date) const;

    // convert
    unsigned int _stringToDate(const std::string &date) const;
};

std::ostream &operator<<(std::ostream &o, Date const &i);

#endif /* ************************************************************ DATE_H */