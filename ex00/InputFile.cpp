/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InputFile.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 17:59:42 by yrabby            #+#    #+#             */
/*   Updated: 2023/06/25 18:19:16 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "InputFile.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

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

InputFile::InputFile(const std::string &file_name, const BitcoinExchange &b)
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
			float exchange = b.getExchangeRate(d);
			
			std::cout << d << " => " << rate << " = " << rate * exchange << std::endl;

		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << line << std::endl;
		}
	}
	file.close();
}

InputFile::InputFile( const InputFile & src )
{
	(void)src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

InputFile::~InputFile()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

InputFile &				InputFile::operator=( InputFile const & rhs )
{
	(void)rhs;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */