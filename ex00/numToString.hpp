/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numToString.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 13:59:26 by yrabby            #+#    #+#             */
/*   Updated: 2023/06/25 13:59:51 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NUMTOSTRING_HPP
# define NUMTOSTRING_HPP

# include <string>
# include <sstream>

template <typename T>
std::string _numToString( T num )
{
	std::ostringstream ss;
	ss << num;
	return ss.str();
}

#endif
