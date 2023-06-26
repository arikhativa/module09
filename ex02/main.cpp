/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:55:51 by yrabby            #+#    #+#             */
/*   Updated: 2023/06/26 13:15:14 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>

# include "Time.hpp"

int main (int ac, char **av)
{
	(void)av;
	if (ac != 2)
	{
		std::cout << "Usage: ./PmergeMe <string>" << std::endl;
		return -1;
	}
	
	Time t;

	usleep(5000);

	t.stop();

	std::cout << t << std::endl;
	return 0;
}