/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 19:11:02 by yrabby            #+#    #+#             */
/*   Updated: 2023/06/26 19:44:48 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe( const PmergeMe & src )
{
	(void)src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PmergeMe::~PmergeMe()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PmergeMe &				PmergeMe::operator=( PmergeMe const & rhs )
{
	(void)rhs;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

// static void	fillList(std::list<unsigned int> &l, const char **numbers)
// {
// 	for (int i = 1; numbers[i]; i++)
// 	{
// 		unsigned int tmp = static_cast<unsigned int>(std::atol(numbers[i]));
// 		l.push_back(tmp);
// 	}
// }

// static void	insertionSort(std::list<unsigned int> &l, int left, int right)
// {
// 	std::list<unsigned int>::iterator it_l = l.begin();
// 	std::list<unsigned int>::iterator it_r = l.begin();
// 	std::list<unsigned int>::iterator it_j = l.begin();

// 	std::advance(it_l, left + 1);
// 	std::advance(it_r, right);
// 	while (*it_l <= *it_r)
// 	{
// 		unsigned int key = *it_l;

// 		unsigned int j = *it_l - 1;
// 		std::advance(it_j, right);
// 		while (j >= left && l[j] > key)
// 		while (j >= left && l[j] > key)
// 		{
// 			l[j + 1] = l[j];
// 			--j;
// 		}
		
// 		l[j + 1] = key;
// 		++it_l
// 	}
// }

// static void	recSortList(std::list<unsigned int> &l, int left, int right, int threshold)
// {
// 	if (right - left + 1 <= threshold)
// 		insertionSort(l, left, right);
// 	else
// 	{
// 		if (left < right)
// 		{
// 			int mid = left + (right - left) / 2;
// 			mergeInsertionSort(l, left, mid, threshold);
// 			mergeInsertionSort(l, mid + 1, right, threshold);
// 			merge(l, left, mid, right);
// 		}
// 	}
// }

// void	PmergeMe::sortList(const char **numbers)
// {
// 	std::list<unsigned int>	l;

// 	fillList(l, numbers);


// }



void insertionSort(std::vector<unsigned int>& arr, unsigned int left, unsigned int right) {
	for (unsigned int i = left + 1; i <= right; ++i) {
		unsigned int key = arr[i];
		unsigned int j = i - 1;
		
		while (j >= left && arr[j] > key) {
			arr[j + 1] = arr[j];
			--j;
		}
		
		arr[j + 1] = key;
	}
}

void merge(std::vector<unsigned int>& arr, unsigned int left, unsigned int mid, unsigned int right) {
	unsigned int n1 = mid - left + 1;
	unsigned int n2 = right - mid;
	
	std::vector<unsigned int> L(n1), R(n2);
	
	for (unsigned int i = 0; i < n1; ++i)
		L[i] = arr[left + i];
	for (unsigned int j = 0; j < n2; ++j)
		R[j] = arr[mid + 1 + j];
	
	unsigned int i = 0, j = 0, k = left;
	
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			++i;
		} else {
			arr[k] = R[j];
			++j;
		}
		++k;
	}
	
	while (i < n1) {
		arr[k] = L[i];
		++i;
		++k;
	}
	
	while (j < n2) {
		arr[k] = R[j];
		++j;
		++k;
	}
}

void mergeInsertionSort(std::vector<unsigned int>& arr, unsigned int left, unsigned int right, unsigned int threshold)
{
	if (right - left + 1 <= threshold)
		insertionSort(arr, left, right);
	{
		if (left < right)
		{
			int mid = left + (right - left) / 2;
			mergeInsertionSort(arr, left, mid, threshold);
			mergeInsertionSort(arr, mid + 1, right, threshold);
			merge(arr, left, mid, right);
		}
	}
}


static void	fillVector(std::vector<unsigned int> &vec, char **numbers)
{
	for (unsigned int i = 1; numbers[i]; i++)
	{
		unsigned int tmp = static_cast<unsigned int>(std::atol(numbers[i]));
		vec[i - 1] = tmp;
	}
}

std::vector<unsigned int>	PmergeMe::sortVector(int size, char **numbers)
{
	std::vector<unsigned int>	vec(size - 1);

	fillVector(vec, numbers);
	return vec;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */