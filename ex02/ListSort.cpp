/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ListSort.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:55:03 by yrabby            #+#    #+#             */
/*   Updated: 2023/10/08 14:29:17 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ListSort.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ListSort::ListSort(char **numbers)
	: _straggler(-1)
{
	for (unsigned int i = 1; numbers[i]; i++)
	{
		unsigned int tmp = static_cast< unsigned int >(std::atol(numbers[i]));
		_list.push_back(tmp);
	}
}

ListSort::ListSort(const ListSort &src)
{
	(void)src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ListSort::~ListSort()
{
	_list.clear();
	_pairs.clear();
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ListSort &ListSort::operator=(ListSort const &rhs)
{
	(void)rhs;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void ListSort::sort(void)
{
	_t.start();
	_mergeInsertSort();
	_t.stop();
}

void ListSort::printTime(void) const
{
	std::cout << "Time to process a range of " << _list.size() << " elements with std::list: " << _t << std::endl;
}

void ListSort::print(void) const
{
	for (std::list< unsigned int >::const_iterator it = _list.begin(); it != _list.end(); it++)
	{
		std::cout << *it;
		if (it != --(_list.end()))
			std::cout << " ";
	}
}

void ListSort::_createPairs(void)
{
	unsigned int a;
	unsigned int b;

	while (_list.size())
	{
		a = _list.back();
		_list.pop_back();
		b = _list.back();
		_list.pop_back();
		std::pair< unsigned int, unsigned int > p(a, b);
		if (p.first < p.second)
			std::swap(p.first, p.second);
		_pairs.push_front(p);
	}
}

void ListSort::_sortByAList(void)
{
	std::list< std::pair< unsigned int, unsigned int > >::iterator it = _pairs.begin();
	for (; it != _pairs.end(); ++it)
	{
		_insertionSortRecursive(it);
	}
}

void ListSort::_insertionSortRecursive(std::list< std::pair< unsigned int, unsigned int > >::iterator it)
{
	if (it == _pairs.begin())
		return;

	std::list< std::pair< unsigned int, unsigned int > >::iterator prev = it;
	--prev;

	if (*it < *prev)
	{
		std::swap(*it, *prev);
		_insertionSortRecursive(prev);
	}
}

::ssize_t ListSort::_binarySearch(unsigned int target, ::ssize_t left, ::ssize_t right)
{
	std::list< unsigned int >::const_iterator tmp = _list.begin();
	std::advance(tmp, left);

	if (right <= left)
		return (target > *tmp ? (left + 1) : left);

	::ssize_t mid = (left + right) / 2;

	tmp = _list.begin();
	std::advance(tmp, mid);

	std::list< unsigned int >::const_iterator mid_iterator = tmp;

	if (target == *mid_iterator)
		return mid + 1;

	if (target > *mid_iterator)
		return _binarySearch(target, mid + 1, right);

	return _binarySearch(target, left, mid - 1);
}

void ListSort::_binaryInsert(unsigned int num)
{
	::ssize_t pos = _binarySearch(num, 0, _list.size() - 1);

	std::list< unsigned int >::iterator it = _list.begin();
	std::advance(it, pos);

	_list.insert(it, num);
}

void ListSort::_mergeBackPairs(void)
{
	::size_t jacob_index = 3;
	::size_t min_limit = Jacobsthal::getIndex(jacob_index - 1) - 1;
	::size_t i = Jacobsthal::getIndex(jacob_index) - 1;

	std::list< std::pair< unsigned int, unsigned int > >::iterator it(_pairs.begin());
	_list.push_front(it->first);
	_list.push_front(it->second);

	while (true)
	{
		it = _pairs.begin();
		std::advance(it, i);

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

void ListSort::_simpleMergeBackPairs(void)
{
	std::list< std::pair< unsigned int, unsigned int > >::iterator it(_pairs.begin());
	_list.push_front(it->first);
	_list.push_front(it->second);

	::size_t i = 1;
	while (i < _pairs.size())
	{
		it = _pairs.begin();
		std::advance(it, i);
		_binaryInsert(it->second);
		_binaryInsert(it->first);
		++i;
	}
}

void ListSort::_mergeInsertSort(void)
{
	if (_list.size() % 2 != 0)
	{
		_straggler = static_cast< ::ssize_t >(_list.back());
		_list.pop_back();
	}

	_createPairs();
	_sortByAList();
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
