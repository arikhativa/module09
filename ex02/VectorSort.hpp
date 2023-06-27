/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorSort.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 10:27:22 by yrabby            #+#    #+#             */
/*   Updated: 2023/06/27 10:38:06 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORSORT_HPP
# define VECTORSORT_HPP

# include <iostream>
# include <string>
# include <vector>
# include <cstdlib>

# include "Time.hpp"

class VectorSort
{

	public:
		VectorSort(int size, char **numbers);
		~VectorSort();

		void	sort(std::size_t const begin, std::size_t const end);

	private:
		VectorSort &		operator=( VectorSort const & rhs );
		VectorSort( VectorSort const & src );

		std::vector<unsigned int> _vec;
		Time _t;

		static const std::size_t _THRESHOLD = 100;

		void _vectorMerge(std::size_t const left, std::size_t const mid, std::size_t const right);
		void _vectorInsertionSort(std::size_t const begin, std::size_t const end);
		void _vectorMergeSort(std::size_t const begin, std::size_t const end);

};


#endif /* ****************************************************** VECTORSORT_H */