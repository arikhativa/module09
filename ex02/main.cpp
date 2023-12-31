/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:55:51 by yrabby            #+#    #+#             */
/*   Updated: 2023/10/09 13:54:58 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	(void)av;
	if (ac < 2)
	{
		std::cout << "Usage: ./PmergeMe <number> <number> ..." << std::endl;
		return -1;
	}
	try
	{
		PmergeMe pm(ac, av);
		pm.sort();
		pm.print();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return -1;
	}
	return 0;
}
