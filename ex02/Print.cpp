#include "Print.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Print::Print()
{
}

Print::Print(const Print &src)
{
	(void)src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Print::~Print()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

std::ostream &operator<<(std::ostream &os, const std::pair< unsigned int, unsigned int > &p)
{
	os << "(" << p.first << ", " << p.second << ")";
	return os;
}

Print &Print::operator=(Print const &rhs)
{
	(void)rhs;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */
