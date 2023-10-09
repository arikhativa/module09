/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 19:11:09 by yrabby            #+#    #+#             */
/*   Updated: 2023/10/08 12:08:31 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include "ListSort.hpp"
#include "Print.hpp"
#include "VectorSort.hpp"

class PmergeMe
{
  public:
	PmergeMe(int ac, char **av);
	~PmergeMe();

	void print(void) const;
	void sort(void);

  private:
	ListSort _list;
	VectorSort _vec;
	char **_av;

	PmergeMe(PmergeMe const &src);
	PmergeMe &operator=(PmergeMe const &rhs);
};

#endif /* ******************************************************** PMERGEME_H */
