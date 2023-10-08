/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorSort.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 10:27:22 by yrabby            #+#    #+#             */
/*   Updated: 2023/10/08 12:08:35 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORSORT_HPP
#define VECTORSORT_HPP

#include <cstdlib>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "Jacobsthal.hpp"
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
	ssize_t _straggler;
	Time _t;

	void _createPairs(void);
	void _sortPairs(void);
	void _sortByAList(void);
	void _sortBIntoA(void);
	void _mergeBackPairs(void);
	void _simpleMergeBackPairs(void);
	void _binaryInsert(unsigned int num);
	void _mergeInsertSort(void);
	void _insertionSortRecursive(const ::ssize_t n);
};

std::ostream &operator<<(std::ostream &os, const std::pair< unsigned int, unsigned int > &p);

#endif /* ****************************************************** VECTORSORT_H */
