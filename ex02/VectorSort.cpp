/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorSort.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 10:28:15 by yrabby            #+#    #+#             */
/*   Updated: 2023/10/07 12:13:01 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "VectorSort.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

static void fillVector(std::vector<unsigned int> &vec, char **numbers)
{
    for (unsigned int i = 1; numbers[i]; i++)
    {
        unsigned int tmp = static_cast<unsigned int>(::atol(numbers[i]));
        vec[i - 1] = tmp;
    }
}

VectorSort::VectorSort(int size, char **numbers) : _vec(size)
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
    for (std::vector<unsigned int>::const_iterator it = _vec.begin(); it != _vec.end(); it++)
    {
        std::cout << *it;
        if (it + 1 != _vec.end())
            std::cout << " ";
    }
}

void void VectorSort::_insertionSort(std::size_t const begin, std::size_t const end)
{
    unsigned int key;
    int j;

    for (std::size_t i = begin; i < end + 1; i++)
    {
        key = _vec[i];
        j = static_cast<int>(i) - 1;
        while (j >= 0 && _vec[j] > key)
        {
            _vec[j + 1] = _vec[j];
            j = j - 1;
        }
        _vec[j + 1] = key;
    }
}

void VectorSort::_mergeInsertSort(void)
{
    _createPairs();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */
