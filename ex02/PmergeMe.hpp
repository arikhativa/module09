/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 19:11:09 by yrabby            #+#    #+#             */
/*   Updated: 2023/06/26 19:38:36 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <list>
# include <vector>
# include <string>
# include <cstdlib>

class PmergeMe
{
	public:
		PmergeMe();
		~PmergeMe();
		// static void	sortList(const char **numbers);
		static std::vector<unsigned int>	sortVector(int size, char **numbers);

	private:
		PmergeMe( PmergeMe const & src );
		PmergeMe &		operator=( PmergeMe const & rhs );

};

#endif /* ******************************************************** PMERGEME_H */