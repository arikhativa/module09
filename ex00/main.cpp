/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:55:51 by yrabby            #+#    #+#             */
/*   Updated: 2023/06/25 18:16:43 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include <iostream>
#include <map>

# include "BitcoinExchange.hpp"
# include "InputFile.hpp"
# include "Date.hpp"

int main (int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./a.out <file>" << std::endl;
		return -1;
	}
	BitcoinExchange b("data.csv");
	InputFile f(av[1], b);
	return 0;
}