/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 12:03:48 by yrabby            #+#    #+#             */
/*   Updated: 2023/06/23 13:21:27 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iterator>

template<class T,class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
	
	/*
	** ------------------------------- ITERATOR --------------------------------
	*/
		typedef typename std::stack<T, Container>::container_type::iterator iterator;
		typedef typename std::stack<T, Container>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T, Container>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T, Container>::container_type::const_reverse_iterator const_reverse_iterator;
	/*
	** ------------------------------- CONSTRUCTOR -----------------------------
	*/

		MutantStack()
			:	std::stack<T, Container>()
		{

		}
		
		MutantStack( MutantStack const & src )
			:	std::stack<T, Container>(src)
		{
		}


	/*
	** -------------------------------- DESTRUCTOR -----------------------------
	*/

		virtual ~MutantStack()
		{
			
		}

	/*
	** --------------------------------- OVERLOAD ------------------------------
	*/

		MutantStack &		operator=( MutantStack const & rhs )
		{
			if ( this != &rhs )
				std::stack<T, Container>::operator=(rhs);
			return *this;
		}

	/*
	** --------------------------------- METHODS -------------------------------
	*/
		iterator begin()
		{
			return this->std::stack<T, Container>::c.begin();
		}

		iterator end()
		{
			return this->std::stack<T, Container>::c.end();
		}
		
		reverse_iterator rbegin()
		{
			return this->std::stack<T, Container>::c.rbegin();
		}

		reverse_iterator rend()
		{
			return this->std::stack<T, Container>::c.rend();
		}

		const_iterator cbegin()
		{
			return this->std::stack<T, Container>::c.begin();
		}

		const_iterator cend()
		{
			return this->std::stack<T, Container>::c.end();
		}

		const_reverse_iterator crbegin()
		{
			return this->std::stack<T, Container>::c.rbegin();
		}

		const_reverse_iterator crend()
		{
			return this->std::stack<T, Container>::c.rend();
		}
};

#endif
