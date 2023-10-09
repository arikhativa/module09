/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorSort.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 10:28:15 by yrabby            #+#    #+#             */
/*   Updated: 2023/10/08 13:51:10 by yrabby           ###   ########.fr       */
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
	, _straggler(-1)
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

void VectorSort::_createPairs(void)
{
	::size_t j = 0;
	for (::size_t i = 0; i < _vec.size(); i += 2)
	{
		std::pair< unsigned int, unsigned int > p(_vec[i], _vec[i + 1]);
		if (p.first < p.second)
			std::swap(p.first, p.second);
		_pairs[j] = p;
		++j;
	}
}

void VectorSort::_sortByAList(void)
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

::ssize_t VectorSort::_binarySearch(unsigned int target, ::ssize_t left, ::ssize_t right)
{
	if (right <= left)
		return (target > _vec[left]) ? (left + 1) : left;

	::ssize_t mid = (left + right) / 2;

	if (target == _vec[mid])
		return mid + 1;

	if (target > _vec[mid])
		return _binarySearch(target, mid + 1, right);

	return _binarySearch(target, left, mid - 1);
}

void VectorSort::_binaryInsert(unsigned int num)
{
	::ssize_t pos = _binarySearch(num, 0, _vec.size() - 1);

	_vec.insert(_vec.begin() + pos, num);
}

void VectorSort::_mergeBackPairs(void)
{
	::size_t jacob_index = 3;
	::size_t min_limit = Jacobsthal::getIndex(jacob_index - 1) - 1;
	::size_t i = Jacobsthal::getIndex(jacob_index) - 1;

	std::vector< std::pair< unsigned int, unsigned int > >::iterator it(_pairs.begin());
	_vec.insert(_vec.begin(), it->first);
	_vec.insert(_vec.begin(), it->second);

	while (true)
	{
		it = _pairs.begin() + i;

		if (i > min_limit)
		{
			_binaryInsert(it->second);
			_binaryInsert(it->first);
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

void VectorSort::_simpleMergeBackPairs(void)
{
	std::vector< std::pair< unsigned int, unsigned int > >::iterator it(_pairs.begin());
	_vec.insert(_vec.begin(), it->first);
	_vec.insert(_vec.begin(), it->second);

	::size_t i = 1;
	while (i < _pairs.size())
	{
		it = _pairs.begin() + i;
		_binaryInsert(it->second);
		_binaryInsert(it->first);
		++i;
	}
}

void VectorSort::_mergeInsertSort(void)
{
	if (_vec.size() % 2 != 0)
	{
		_straggler = static_cast< ::ssize_t >(_vec.back());
		_vec.pop_back();
	}

	_createPairs();
	_sortByAList();

	_vec.clear();

	if (_pairs.size() > 3)
		_mergeBackPairs();
	else
		_simpleMergeBackPairs();

	if (_straggler != -1)
		_binaryInsert(static_cast< unsigned int >(_straggler));

	_straggler = -1;
	_pairs.clear();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */
