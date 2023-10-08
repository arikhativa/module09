/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 19:11:02 by yrabby            #+#    #+#             */
/*   Updated: 2023/10/08 14:28:59 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

static void checkNumber(char *str)
{
	for (int i = 0; str[i]; ++i)
	{
		if (!std::isdigit(str[i]))
			throw std::invalid_argument("Invalid argument");
	}
}

PmergeMe::PmergeMe(int ac, char **av)
	: _list(av)
	, _vec(ac - 1, av)
	, _av(av)
{
	++av;
	while (*av)
	{
		checkNumber(*av);
		++av;
	}
}

PmergeMe::PmergeMe(const PmergeMe &src)
	: _list(NULL)
	, _vec(0, NULL)
{
	(void)src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PmergeMe::~PmergeMe()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs)
{
	(void)rhs;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void PmergeMe::sort(void)
{
	_list.sort();
	// _vec.sort();
}

static void printArray(char **av)
{
	for (int i = 1; av[i]; ++i)
	{
		std::cout << av[i];
		if (av[i + 1])
			std::cout << " ";
	}
}

void PmergeMe::print(void) const
{
	std::cout << "Before:\t";
	printArray(_av);
	std::cout << std::endl;
	std::cout << "After:\t";
	// _list.print();
	_vec.print();
	std::cout << std::endl;
	_vec.printTime();
	// _list.printTime();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */
