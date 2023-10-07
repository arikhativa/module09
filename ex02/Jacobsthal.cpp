#include "Jacobsthal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Jacobsthal::Jacobsthal()
{
}

Jacobsthal::Jacobsthal(const Jacobsthal &src)
{
	(void)src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Jacobsthal::~Jacobsthal()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Jacobsthal &Jacobsthal::operator=(Jacobsthal const &rhs)
{
	(void)rhs;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/
::size_t getIndex(::size_t i)
{
	if (i == 0)
		return 1;
	else if (i == 1)
		return 1;
	return i + 2 * (i - 1);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */
