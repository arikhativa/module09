/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 19:11:02 by yrabby            #+#    #+#             */
/*   Updated: 2023/06/27 14:38:19 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PmergeMe::PmergeMe(int ac, char **av)
	: _vec(ac, av), _av(av)
{
}

PmergeMe::PmergeMe( const PmergeMe & src )
	:	_vec(0, NULL)
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

PmergeMe &				PmergeMe::operator=( PmergeMe const & rhs )
{
	(void)rhs;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/


void	PmergeMe::sort(void)
{
	_vec.sort();
}

static void	printArray(char **av)
{
	for (int i = 1; av[i]; ++i)
	{
		std::cout << av[i];
		if (av[i + 1])
			std::cout << " ";
	}
}

void	PmergeMe::print(void) const
{
	std::cout << "Before:\t";
	printArray(_av);
	std::cout << std::endl;
	std::cout << "After:\t";
	_vec.print();
	std::cout << std::endl;
	_vec.printTime();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */