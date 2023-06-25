/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InputFile.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 17:58:28 by yrabby            #+#    #+#             */
/*   Updated: 2023/06/25 18:12:06 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUTFILE_HPP
# define INPUTFILE_HPP

# include <iostream>
# include <string>
# include <fstream>

# include "BitcoinExchange.hpp"
# include "Date.hpp"

class InputFile
{

	public:
		explicit InputFile(const std::string &file_name, const BitcoinExchange &b);
		~InputFile();

	private:
		InputFile( InputFile const & src );
		InputFile &		operator=( InputFile const & rhs );
	
};

#endif /* ******************************************************* INPUTFILE_H */