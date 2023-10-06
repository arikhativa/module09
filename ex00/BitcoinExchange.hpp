/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 12:54:39 by yrabby            #+#    #+#             */
/*   Updated: 2023/10/06 15:21:36 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <exception>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

#include "Date.hpp"

class BitcoinExchange
{

  public:
    explicit BitcoinExchange(const std::string &file_name);
    ~BitcoinExchange();

    float getExchangeRate(const Date &date) const;

  private:
    BitcoinExchange(BitcoinExchange const &src);
    BitcoinExchange &operator=(BitcoinExchange const &rhs);

    std::map<Date, float> _exchange_rate;
};

#endif /* ************************************************* BITCOINEXCHANGE_H */