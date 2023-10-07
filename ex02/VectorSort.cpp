/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorSort.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 10:28:15 by yrabby            #+#    #+#             */
/*   Updated: 2023/10/07 18:32:52 by yrabby           ###   ########.fr       */
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
	for (::size_t i = 0; i < _vec.size(); ++i)
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
	std::vector< std::pair< unsigned int, unsigned int > >::iterator it(_pairs.begin());

	_vec.clear();
	for (::size_t i = 0; i < _pairs.size(); ++i)
	{
		_vec.insert(_vec.begin() + i, it->first);
		++it;
	}
}

::ssize_t binarySearch(const std::vector< unsigned int > &vec, unsigned int target, ::ssize_t left, ::ssize_t right)
{
	if (right <= left)
		return (target > vec[left]) ? (left + 1) : left;

	::ssize_t mid = (left + right) / 2;
	if (mid >= vec.size())
	{
		std::cout << "left: " << left << std::endl;
		std::cout << "right: " << right << std::endl;
		std::cout << "ERR: " << mid << std::endl;
	}

	if (target == vec[mid])
		return mid + 1;

	if (target > vec[mid])
		return binarySearch(vec, target, mid + 1, right);

	return binarySearch(vec, target, left, mid - 1);
}

void VectorSort::_binaryInsert(unsigned int num, ::size_t i)
{
	::size_t right = _vec.size() - 1;
	::ssize_t pos = binarySearch(_vec, num, 0, right);

	_vec.insert(_vec.begin() + pos, num);
}

// TODO think of size 2!
void VectorSort::_returnB(void)
{
	::size_t jacob_index = 3;
	::size_t min_limit = Jacobsthal::getIndex(jacob_index - 1) - 1;
	::size_t i = Jacobsthal::getIndex(jacob_index) - 1;

	std::vector< std::pair< unsigned int, unsigned int > >::iterator it(_pairs.begin());
	_vec.insert(_vec.begin(), it->first);
	_vec.insert(_vec.begin(), it->second);
	while (i < _pairs.size())
	{
		it = _pairs.begin() + i;

		if (i > min_limit)
		{
			_binaryInsert(it->second, i);
			_binaryInsert(it->first, i);
			--i;
		}
		else
		{
			++jacob_index;
			min_limit = Jacobsthal::getIndex(jacob_index - 1) - 1;
			i = Jacobsthal::getIndex(jacob_index) - 1;
			if (min_limit >= _pairs.size() - 1)
			{
				break;
			}
			while (i > _pairs.size() - 1)
				--i;
		}
	}
}

void VectorSort::_mergeInsertSort(void)
{
	printVector(_vec);
	_createPairs();
	_sortPairs();
	_sortAList();
	// _returnA();
	_vec.clear();
	printVector(_pairs);
	_returnB();
	printVector(_vec);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */
