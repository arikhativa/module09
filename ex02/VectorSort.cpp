/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorSort.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 10:28:15 by yrabby            #+#    #+#             */
/*   Updated: 2023/10/07 13:18:36 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "VectorSort.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

static void fillVector(std::vector< unsigned int > &vec, char **numbers)
{
	for (unsigned int i = 1; numbers[i]; i++)
	{
		unsigned int tmp = static_cast< unsigned int >(::atol(numbers[i]));
		vec[i - 1] = tmp;
	}
}

VectorSort::VectorSort(int size, char **numbers)
	: _vec(size)
	, _pairs(size / 2)
{
	fillVector(_vec, numbers);
}

VectorSort::VectorSort(const VectorSort &src)
{
	(void)src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

VectorSort::~VectorSort()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

VectorSort &VectorSort::operator=(VectorSort const &rhs)
{
	(void)rhs;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void VectorSort::sort(void)
{
	_t.start();
	_mergeInsertSort();
	_t.stop();
}

void VectorSort::printTime(void) const
{
	std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector: " << _t << std::endl;
}

void VectorSort::print(void) const
{
	for (std::vector< unsigned int >::const_iterator it = _vec.begin(); it != _vec.end(); it++)
	{
		std::cout << *it;
		if (it + 1 != _vec.end())
			std::cout << " ";
	}
}

std::ostream &operator<<(std::ostream &os, const std::pair< unsigned int, unsigned int > &p)
{
	os << "(" << p.first << ", " << p.second << ")";
	return os;
}

void VectorSort::_createPairs(void)
{
	::size_t j = 0;
	for (::size_t i = 0; i < _vec.size(); i += 2)
	{
		std::pair< unsigned int, unsigned int > p(_vec[i], _vec[i + 1]);
		_pairs[j] = p;
		++j;
	}
}

void swap(std::pair< unsigned int, unsigned int > &p)
{
	unsigned int tmp = p.first;
	p.first = p.second;
	p.second = tmp;
}

void VectorSort::_sortPairs(void)
{
	for (::size_t i = 0; i < _vec.size(); i += 2)
	{
		std::pair< unsigned int, unsigned int > &p(_pairs[i]);
		if (p.first < p.second)
			swap(p);
	}
}

void VectorSort::_sortAList(void)
{
	_insertionSortRecursive(_pairs.size());
}

void VectorSort::_insertionSortRecursive(::ssize_t n)
{
	if (n <= 1)
		return;

	_insertionSortRecursive(n - 1);

	std::pair< unsigned int, unsigned int > last(_pairs[n - 1]);
	int j = n - 2;

	while (j >= 0 && _pairs[j].first > last.first)
	{
		_pairs[j + 1] = _pairs[j];
		j--;
	}
	_pairs[j + 1] = last;
}

template < typename T >
void printVector(const std::vector< T > &vec)
{
	typename std::vector< T >::const_iterator it;

	for (it = vec.begin(); it != vec.end(); ++it)
	{
		std::cout << *it << " ";
	}

	std::cout << std::endl;
}

void VectorSort::_mergeInsertSort(void)
{
	_createPairs();
	_sortPairs();
	_sortAList();
	printVector(_pairs);
	// _sortBIntoA();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */
