/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ListSort.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:52:15 by yrabby            #+#    #+#             */
/*   Updated: 2023/10/09 13:54:57 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTSORT_HPP
#define LISTSORT_HPP

#include <cstdlib>
#include <iostream>
#include <list>
#include <string>

#include "Jacobsthal.hpp"
#include "Print.hpp"
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
	std::list< unsigned int > _list;
	std::list< std::pair< unsigned int, unsigned int > > _pairs;
	ssize_t _straggler;
	Time _t;

	ListSort();
	ListSort(ListSort const &src);
	ListSort &operator=(ListSort const &rhs);

	void _createPairs(void);
	void _sortByAList(void);
	void _sortBIntoA(void);
	::ssize_t _binarySearch(unsigned int target, ::ssize_t left, ::ssize_t right);
	void _mergeBackPairs(void);
	void _simpleMergeBackPairs(void);
	void _binaryInsert(unsigned int num);
	void _mergeInsertSort(void);
	void _insertionSortRecursive(std::list< std::pair< unsigned int, unsigned int > >::iterator it);
};

#endif /* ******************************************************** LISTSORT_H */
