/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorSort.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 10:27:22 by yrabby            #+#    #+#             */
/*   Updated: 2023/10/06 16:38:36 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORSORT_HPP
#define VECTORSORT_HPP

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "Time.hpp"

class VectorSort
{
  public:
    VectorSort(int size, char **numbers);
    ~VectorSort();

    void sort(void);
    void printTime(void) const;
    void print(void) const;

  private:
    static const std::size_t _THRESHOLD = 100;

    VectorSort &operator=(VectorSort const &rhs);
    VectorSort(VectorSort const &src);

    std::vector<unsigned int> _vec;
    Time _t;

    void _merge(std::size_t const left, std::size_t const mid, std::size_t const right);
    void _insertionSort(std::size_t const begin, std::size_t const end);
    void _mergeSort(std::size_t const begin, std::size_t const end);
};

#endif /* ****************************************************** VECTORSORT_H */
