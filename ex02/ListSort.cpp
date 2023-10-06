/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ListSort.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:55:03 by yrabby            #+#    #+#             */
/*   Updated: 2023/10/06 16:38:56 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ListSort.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ListSort::ListSort(char **numbers)
{
    for (unsigned int i = 1; numbers[i]; i++)
    {
        unsigned int tmp = static_cast<unsigned int>(std::atol(numbers[i]));
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
    _mergeSort(_list);
    _t.stop();
}

void ListSort::printTime(void) const
{
    std::cout << "Time to process a range of " << _list.size() << " elements with std::list: " << _t << std::endl;
}

void ListSort::print(void) const
{
    for (std::list<unsigned int>::const_iterator it = _list.begin(); it != _list.end(); it++)
    {
        std::cout << *it;
        if (it != --(_list.end()))
            std::cout << " ";
    }
}

void ListSort::_insertionSort(std::list<unsigned int> &list) const
{
    std::list<unsigned int>::iterator it = list.begin();
    std::list<unsigned int>::iterator j = list.begin();
    std::list<unsigned int>::iterator tmp = list.begin();
    ++it;

    while (it != list.end())
    {
        unsigned int key = *it;
        j = it;
        --j;
        while (j != list.begin() && *j > key)
        {
            tmp = j;
            ++tmp;
            std::iter_swap(j, tmp);
            --j;
        }

        if (*j > key)
        {
            tmp = j;
            ++tmp;
            std::iter_swap(j, tmp);
            --j;
        }
        ++j;
        *j = key;
        ++it;
    }
}

void ListSort::_merge(std::list<unsigned int> &left, std::list<unsigned int> &list)
{
    std::list<unsigned int>::iterator it_left = left.begin();
    std::list<unsigned int>::iterator tmp = left.begin();
    std::list<unsigned int>::iterator it_main = list.begin();

    while (it_left != left.end() && it_main != list.end())
    {
        if (*it_left < *it_main)
        {
            tmp = left.erase(it_left);
            list.insert(it_main, *it_left);
            it_left = tmp;
        }
        else
            ++it_main;
    }
    while (it_left != left.end())
    {
        tmp = left.erase(it_left);
        list.push_back(*it_left);
        it_left = tmp;
    }
}

void ListSort::_mergeSort(std::list<unsigned int> &list)
{
    std::size_t size = list.size();

    if (size <= _THRESHOLD)
    {
        _insertionSort(list);
        return;
    }

    if (list.size() <= 1)
        return;

    std::size_t mid = size / 2;
    std::list<unsigned int> left;
    std::list<unsigned int> right;

    std::list<unsigned int>::iterator it = list.begin();
    std::advance(it, mid);
    left.splice(left.begin(), list, list.begin(), it);

    _mergeSort(left);
    _mergeSort(list);
    _merge(left, list);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */
