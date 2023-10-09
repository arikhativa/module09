/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Time.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:23:42 by yrabby            #+#    #+#             */
/*   Updated: 2023/10/09 13:55:06 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_HPP
#define TIME_HPP

#include <iostream>
#include <string>
#include <sys/time.h>

class Time
{

  public:
	Time();
	Time(Time const &src);
	~Time();

	Time &operator=(Time const &rhs);

	void start(void);
	void stop(void);
	std::string getDuration(void) const;

  private:
	struct timeval _start;
	struct timeval _end;
};

std::ostream &operator<<(std::ostream &o, Time const &i);

#endif /* ************************************************************ TIME_H */
