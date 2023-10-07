/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorSort.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 10:27:22 by yrabby            #+#    #+#             */
/*   Updated: 2023/10/07 15:14:00 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORSORT_HPP
#define VECTORSORT_HPP

#include <cstdlib>
#include <iostream>
#include <string>
#include <utility>
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
	VectorSort &operator=(VectorSort const &rhs);
	VectorSort(VectorSort const &src);

	std::vector< unsigned int > _vec;
	std::vector< std::pair< unsigned int, unsigned int > > _pairs;
	Time _t;

	void _createPairs(void);
	void _sortPairs(void);
	void _sortAList(void);
	void _sortBIntoA(void);
	void _returnA(void);
	void _returnB(void);
	void _mergeInsertSort(void);
	void _insertionSortRecursive(const ::ssize_t n);
};

std::ostream &operator<<(std::ostream &os, const std::pair< unsigned int, unsigned int > &p);

#endif /* ****************************************************** VECTORSORT_H */
