/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:55:51 by yrabby            #+#    #+#             */
/*   Updated: 2023/06/23 13:21:32 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include <iterator>
#include <iostream>

#include "MutantStack.hpp"

void	iter_test()
{
	MutantStack<int> mstack;

	mstack.push(1);
	mstack.push(2);
	
	MutantStack<int>::iterator it = mstack.begin();

	while (it != mstack.end())
	{
		*it += 1;
		std::cout << *it << std::endl;
		it++;
	}
}

void	const_iter_test()
{
	MutantStack<int> mstack;

	mstack.push(1);
	mstack.push(2);
	
	MutantStack<int>::const_iterator it = mstack.cbegin();

	while (it != mstack.cend())
	{
		std::cout << *it << std::endl;
		it++;
	}
}

void	rev_iter_test()
{
	MutantStack<int> mstack;

	mstack.push(1);
	mstack.push(2);
	
	MutantStack<int>::reverse_iterator it = mstack.rbegin();

	while (it != mstack.rend())
	{
		*it += 10;
		std::cout << *it << std::endl;
		it++;
	}
}

void	const_rev_iter_test()
{
	MutantStack<int> mstack;

	mstack.push(-1);
	mstack.push(-2);
	
	MutantStack<int>::const_reverse_iterator it = mstack.crbegin();

	while (it != mstack.crend())
	{
		std::cout << *it << std::endl;
		it++;
	}
}

void	subject()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	s.pop();
	s.pop();
	std::cout << s.top() << std::endl;
	std::cout << mstack.top() << std::endl;
	
}

void	extra_test()
{
	{
		MutantStack<int> mstack;
		MutantStack<int> mstack2;

		mstack.push(1);
		mstack.push(2);

		mstack2 = mstack;

		std::cout << mstack2.top() << std::endl;
	}
	{
		MutantStack<int> mstack;

		mstack.push(1);
		mstack.push(2);

		MutantStack<int> mstack2(mstack);

		std::cout << mstack2.top() << std::endl;
	}
	
}

int main(void)
{
	iter_test();
	rev_iter_test();
	const_iter_test();
	const_rev_iter_test();
	subject();
	extra_test();
	return 0;
}