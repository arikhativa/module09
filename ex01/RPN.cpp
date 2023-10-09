/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:00:41 by yrabby            #+#    #+#             */
/*   Updated: 2023/10/09 13:54:52 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RPN::RPN()
{
}

RPN::RPN(const RPN &src)
{
	(void)src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RPN::~RPN()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RPN &RPN::operator=(RPN const &rhs)
{
	(void)rhs;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

static void _handelOperator(char c, std::stack< int > &stack)
{
	if (stack.size() < 2)
		throw std::invalid_argument("Error: not enough values");
	int a = stack.top();
	stack.pop();
	int b = stack.top();
	stack.pop();
	switch (c)
	{
	case '+':
		stack.push(b + a);
		break;
	case '-':
		stack.push(b - a);
		break;
	case '*':
		stack.push(b * a);
		break;
	case '/':
		stack.push(b / a);
		break;
	default:
		throw std::invalid_argument("Error: invalid operator");
	}
}

static bool _isOperator(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

int RPN::evaluate(const std::string &input)
{
	std::stack< int > stack;

	for (std::string::const_iterator it = input.begin(); it != input.end(); ++it)
	{
		if (std::isdigit(*it))
			stack.push(*it - '0');
		else if (*it == '-' && std::isdigit(*(it + 1)))
		{
			stack.push(-1 * (*(it + 1) - '0'));
			++it;
		}
		else if (_isOperator(*it))
			_handelOperator(*it, stack);
		else if (*it != ' ')
			throw std::invalid_argument("Error: invalid character");
	}
	if (stack.size() != 1)
		throw std::invalid_argument("Error: too many values");
	return stack.top();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */
