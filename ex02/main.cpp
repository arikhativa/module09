/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:55:51 by yrabby            #+#    #+#             */
/*   Updated: 2023/06/26 19:44:15 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Time.hpp"
# include "PmergeMe.hpp"

void	printVector(std::vector<unsigned int> &vec)
{
	std::cout << "[" ;
	for (std::vector<unsigned int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		std::cout << *it;
		if (it + 1 != vec.end())
			std::cout << ", ";
	}
	std::cout << "]" << std::endl;;
}

int main (int ac, char **av)
{
	(void)av;
	if (ac < 2)
	{
		std::cout << "Usage: ./PmergeMe <number> <number> ..." << std::endl;
		return -1;
	}
	std::vector<unsigned int> vec = PmergeMe::sortVector(ac, av);
	printVector(vec);
	return 0;
}