/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ListSort.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:52:15 by yrabby            #+#    #+#             */
/*   Updated: 2023/10/06 16:38:53 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTSORT_HPP
#define LISTSORT_HPP

#include <cstdlib>
#include <iostream>
#include <list>
#include <string>

#include "Time.hpp"

class ListSort
{
  public:
    explicit ListSort(char **numbers);
    ~ListSort();

    void sort(void);
    void printTime(void) const;
    void print(void) const;

  private:
    static const std::size_t _THRESHOLD = 100;

    std::list<unsigned int> _list;
    Time _t;

    ListSort(ListSort const &src);
    ListSort &operator=(ListSort const &rhs);

    void _merge(std::list<unsigned int> &left, std::list<unsigned int> &list);
    void _insertionSort(std::list<unsigned int> &list) const;
    void _mergeSort(std::list<unsigned int> &list);
};

#endif /* ******************************************************** LISTSORT_H */
