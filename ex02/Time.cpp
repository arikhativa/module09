/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Time.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:19:07 by yrabby            #+#    #+#             */
/*   Updated: 2023/10/06 16:41:18 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Time.hpp"
#include "numToString.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Time::Time()
{
    gettimeofday(&_start, NULL);
    gettimeofday(&_end, NULL);
}

Time::Time(const Time &src) : _start(src._start), _end(src._end)
{
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Time::~Time()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Time &Time::operator=(Time const &rhs)
{
    if (this != &rhs)
    {
        _start = rhs._start;
        _end = rhs._end;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &o, Time const &i)
{
    o << i.getDuration() << " us";
    return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Time::start(void)
{
    gettimeofday(&_start, NULL);
}

void Time::stop(void)
{
    gettimeofday(&_end, NULL);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Time::getDuration(void) const
{
    time_t sec = _end.tv_sec - _start.tv_sec;
    suseconds_t us = _end.tv_usec - _start.tv_usec;
    if (us < 0)
    {
        --sec;
        us += 1000000;
    }

    return _numToString<time_t>(sec) + "." + _numToString<time_t>(us);
}

/* ************************************************************************** */
