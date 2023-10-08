/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ListSort.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:52:15 by yrabby            #+#    #+#             */
/*   Updated: 2023/10/08 14:28:52 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTSORT_HPP
#define LISTSORT_HPP

#include <cstdlib>
#include <iostream>
#include <list>
#include <string>

#include "Jacobsthal.hpp"
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

	std::list< unsigned int > _list;
	std::list< std::pair< unsigned int, unsigned int > > _pairs;
	ssize_t _straggler;
	Time _t;

	ListSort(ListSort const &src);
	ListSort &operator=(ListSort const &rhs);

	void _createPairs(void);
	void _sortByAList(void);
	void _sortBIntoA(void);
	void _mergeBackPairs(void);
	void _simpleMergeBackPairs(void);
	void _binaryInsert(unsigned int num);
	void _mergeInsertSort(void);
	void _insertionSortRecursive(std::list< std::pair< unsigned int, unsigned int > >::iterator it);
};

// TODO
std::ostream &operator<<(std::ostream &os, const std::pair< unsigned int, unsigned int > &p);

template < typename T >
void printList(const std::list< T > &l)
{
	for (typename std::list< T >::const_iterator it = l.begin(); it != l.end(); it++)
	{
		std::cout << *it;
		if (it != --(l.end()))
			std::cout << " ";
	}
	std::cout << std::endl;
}

#endif /* ******************************************************** LISTSORT_H */
