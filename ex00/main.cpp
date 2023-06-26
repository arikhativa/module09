/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:55:51 by yrabby            #+#    #+#             */
/*   Updated: 2023/06/26 09:35:48 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <climits>

# include "BitcoinExchange.hpp"
# include "Date.hpp"

static void	validateLine(const std::string &line)
{
	Date d(line.substr(0, 10));
	std::string sep(line.substr(10, 3));
	if (" | " != sep)
	{
		std::cout << "sep: '" << sep << "'" << std::endl;
		throw std::invalid_argument("Invalid separator");	
	}
	std::string rate = line.substr(13, -1);
	if (rate.find_first_not_of("-0123456789.") != std::string::npos)
		throw std::invalid_argument("Invalid rate: not a number");
}

static void	execFile(const std::string &file_name, const BitcoinExchange &b)
{
	std::fstream file;

	file.open(file_name.c_str(), std::ios::in);
	if (!file.is_open() || !file.good())
		throw std::invalid_argument("Failed to open file");

	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		try
		{
			validateLine(line);
			std::string rate_str = line.substr(13, -1);
			Date d(line.substr(0, 10));
			float rate  = static_cast<float>(std::strtod(rate_str.c_str(), NULL));
			if (rate < 0) 
				throw std::invalid_argument("Error: not a positive number.");
			if (static_cast<double>(INT_MAX) < static_cast<double>(rate))
				throw std::invalid_argument("Error: too large a number.");
			float exchange = b.getExchangeRate(d);
			if (exchange == -1)
				throw std::invalid_argument("Error: no exchange rate for this date.");
			
			std::cout << d << " => " << rate << " = " << rate * exchange << std::endl;

		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	file.close();

}

int main (int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./a.out <file>" << std::endl;
		return -1;
	}
	BitcoinExchange b("data.csv");
	execFile(av[1], b);
	return 0;
}