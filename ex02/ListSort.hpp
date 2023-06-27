/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ListSort.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:52:15 by yrabby            #+#    #+#             */
/*   Updated: 2023/06/27 17:59:56 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTSORT_HPP
# define LISTSORT_HPP

# include <iostream>
# include <list>
# include <string>
# include <cstdlib>

# include "Time.hpp"

class ListSort
{

	public:
		explicit ListSort(char **numbers);
		~ListSort();

		void	sort(void);
		void	printTime(void) const;
		void	print(void) const;

	private:
		static const std::size_t _THRESHOLD = 100;

		std::list<unsigned int>	_list;
		Time					_t;
		
		ListSort( ListSort const & src );
		ListSort &		operator=( ListSort const & rhs );

		void _merge(std::list<unsigned int> &left, std::list<unsigned int> &list);
		void _insertionSort(std::list<unsigned int> &list);
		void _mergeSort(std::list<unsigned int> &list);

};

std::ostream &			operator<<( std::ostream & o, ListSort const & i );

#endif /* ******************************************************** LISTSORT_H */