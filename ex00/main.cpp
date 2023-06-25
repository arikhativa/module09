/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:55:51 by yrabby            #+#    #+#             */
/*   Updated: 2023/06/25 17:48:25 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include <iostream>
#include <map>

# include "BitcoinExchange.hpp"
# include "Date.hpp"

int main ()
{
	BitcoinExchange b("data.csv");
	// {
	// 	Date d("2019-05-16");
	// 	std::cout << b.getExchangeRate(d) << std::endl;
	// 	d = Date("2019-05-17");
	// 	std::cout << b.getExchangeRate(d) << std::endl;
	// 	d = Date("2019-05-18");
	// 	std::cout << b.getExchangeRate(d) << std::endl;
	// }
	// {
	// 	Date d("2009-01-01");
	// 	std::cout << b.getExchangeRate(d) << std::endl;
	// 	d = Date("2009-01-02");
	// 	std::cout << b.getExchangeRate(d) << std::endl;
	// 	d = Date("2009-01-03");
	// 	std::cout << b.getExchangeRate(d) << std::endl;
	// 	d = Date("2022-03-29");
	// 	std::cout << b.getExchangeRate(d) << std::endl;
	// 	d = Date("3009-01-02");
	// 	std::cout << b.getExchangeRate(d) << std::endl;
	// }
	return 0;

}