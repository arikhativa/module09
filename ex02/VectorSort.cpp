/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorSort.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 10:28:15 by yrabby            #+#    #+#             */
/*   Updated: 2023/10/07 15:45:02 by yrabby           ###   ########.fr       */
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

void VectorSort::_returnA(void)
{
	std::vector< unsigned int >::iterator it_vec(_vec.begin());
	std::vector< std::pair< unsigned int, unsigned int > >::iterator it_pair(_pairs.begin());

	std::fill(_vec.begin(), _vec.end(), 0);
	for (::size_t i = 0; i < (_vec.size() / 2); ++i)
	{
		*it_vec = it_pair->first;
		++it_pair;
		++it_vec;
	}
}

void VectorSort::_binaryInsert(unsigned int num, ::size_t i, ::size_t left, ::size_t right)
{
	::size_t pos = binarySearch(_vec, num, left, right);

	// _vec.insert(_vec.begin() + min - 1, _pairs.begin()->second);
}

::size_t binarySearch(const std::vector< unsigned int > &vec, unsigned int target, ::size_t left, ::size_t right)
{
	if (right <= left)
		return (target > vec[left]) ? (left + 1) : left;

	::size_t mid = (left + right) / 2;

	if (target == vec[mid])
		return mid + 1;

	if (target > vec[mid])
		return binarySearch(vec, target, mid + 1, right);

	return binarySearch(vec, target, left, mid - 1);
}

// TODO think of num 2!
void VectorSort::_returnB(void)
{
	_vec.insert(_vec.begin(), _pairs.begin()->second);

	::size_t jacob_index = 3;
	::size_t min_limit = 1;
	::size_t i = 3;
	while (i < _pairs.size())
	{
		std::pair< unsigned int, unsigned int > p(_pairs.begin() + i);

		_binaryInsert(p->second, i, min_limit, jacob_index);
	}
}

void VectorSort::_mergeInsertSort(void)
{
	_createPairs();
	_sortPairs();
	_sortAList();
	_returnA();
	_returnB();
	printVector(_pairs);
	printVector(_vec);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */
