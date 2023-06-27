/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:55:51 by yrabby            #+#    #+#             */
/*   Updated: 2023/06/27 18:27:45 by yrabby           ###   ########.fr       */
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



void	_print(std::list<unsigned int> &_list)
{
	for (std::list<unsigned int>::const_iterator it = _list.begin(); it != _list.end(); it++)
	{
		std::cout << *it;
		if (it != --(_list.end()))
			std::cout << " ";
	}
}


int main (int ac, char **av)
{
	(void)av;
	if (ac < 2)
	{
		std::cout << "Usage: ./PmergeMe <number> <number> ..." << std::endl;
		return -1;
	}
	PmergeMe pm(ac, av);

	pm.sort();
	pm.print();

	// std::list<unsigned int> list1;
	// std::list<unsigned int> list2;

	// list1.push_back(1);
	// list1.push_back(2);
	// list1.push_back(3);
	// list1.push_back(4);
	// list1.push_back(5);
	// list1.push_back(6);

	// std::size_t mid = list1.size() / 2;
	// std::list<unsigned int>::iterator it = list1.begin();
	// std::advance(it, mid);
	// list2.splice(list2.begin(), list1, list1.begin(), it);

	// std::cout << " -- " << std::endl;
	
	// _print(list1);
	// std::cout << std::endl;
	// _print(list2);

	// std::cout << std::endl;


	return 0;
}