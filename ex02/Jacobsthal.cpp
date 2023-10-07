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
::size_t Jacobsthal::getIndex(::size_t i)
{
	if (i == 0)
		return 0;
	else if (i == 1)
		return 1;
	else
	{
		size_t j_n_minus_1 = 1;
		size_t j_n_minus_2 = 0;
		size_t j_n;

		for (size_t n = 2; n <= i; ++n)
		{
			j_n = j_n_minus_1 + 2 * j_n_minus_2;
			j_n_minus_2 = j_n_minus_1;
			j_n_minus_1 = j_n;
		}

		return j_n;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */
