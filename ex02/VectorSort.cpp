/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorSort.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 10:28:15 by yrabby            #+#    #+#             */
/*   Updated: 2023/06/27 10:34:58 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "VectorSort.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

static void	fillVector(std::vector<unsigned int> &vec, char **numbers)
{
	for (unsigned int i = 1; numbers[i]; i++)
	{
		unsigned int tmp = static_cast<unsigned int>(std::atol(numbers[i]));
		vec[i - 1] = tmp;
	}
}


VectorSort::VectorSort(int size, char **numbers)
	:	_vec(size - 1)
{
	fillVector(_vec, numbers);
}

VectorSort::VectorSort( const VectorSort & src )
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

VectorSort &				VectorSort::operator=( VectorSort const & rhs )
{
	(void)rhs;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/


void VectorSort::_vectorMerge(std::size_t const left,
						std::size_t const mid,
						std::size_t const right)
{

	std::vector<unsigned int> sub_left(mid - left + 1);
	std::vector<unsigned int> sub_right(right - mid);

	for (std::size_t i = 0; i < sub_left.size(); ++i)
		sub_left[i] = _vec[left + i];
	for (std::size_t i = 0; i < sub_right.size(); ++i)
		sub_right[i] = _vec[mid + 1 + i];

	std::size_t sub_left_index = 0;
	std::size_t sub_right_index = 0;
	std::size_t main_index = left;

	while (sub_left_index < sub_left.size() && sub_right_index < sub_right.size())
	{
		if (sub_left[sub_left_index] < sub_right[sub_right_index])
		{
			_vec[main_index] = sub_left[sub_left_index];
			++sub_left_index;
		}
		else
		{
			_vec[main_index] = sub_right[sub_right_index];
			++sub_right_index;
		}
		++main_index;
	}
	while (sub_left_index < sub_left.size())
	{
		_vec[main_index] = sub_left[sub_left_index];
		++sub_left_index;
		++main_index;
	}
	while (sub_right_index < sub_right.size())
	{
		_vec[main_index] = sub_right[sub_right_index];
		++sub_right_index;
		++main_index;
	}
}

void VectorSort::_vectorInsertionSort(std::size_t const begin, std::size_t const end)
{
	unsigned int key;
	int j;
	
	for (std::size_t i = begin; i < end + 1; i++)
	{
		key = _vec[i];
		j = i - 1;
		while (j >= 0 && _vec[j] > key)
		{
			_vec[j + 1] = _vec[j];
			j = j - 1;
		}
		_vec[j + 1] = key;
	}
}

void VectorSort::_vectorMergeSort(std::size_t const begin, std::size_t const end)
{
 	if (end - begin + 1 <= _THRESHOLD) {
		_vectorInsertionSort(begin, end);
		return;
	}
	if (begin >= end)
		return;
	std::size_t mid = begin + (end - begin) / 2;
	_vectorMergeSort(begin, mid);
	_vectorMergeSort(mid + 1, end);
	_vectorMerge(begin, mid, end);
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */