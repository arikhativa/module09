/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 12:54:39 by yrabby            #+#    #+#             */
/*   Updated: 2023/06/25 14:16:21 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <exception>
# include <iostream>
# include <string>
# include <map>
# include <fstream>

# include "Date.hpp"

class BitcoinExchange
{

	public:

		explicit BitcoinExchange(const std::string &file_name);
		~BitcoinExchange();

		float	getExchangeRate(const Date &date) const;

	private:
		BitcoinExchange( BitcoinExchange const & src );
		BitcoinExchange &		operator=( BitcoinExchange const & rhs );

		std::map<Date, float>	_exchange_rate;

};

#endif /* ************************************************* BITCOINEXCHANGE_H */