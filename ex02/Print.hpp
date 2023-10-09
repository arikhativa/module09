#ifndef PRINT_HPP
#define PRINT_HPP

#include <iostream>
#include <list>

class Print
{
  private:
	Print();
	Print(Print const &src);
	~Print();

	Print &operator=(Print const &rhs);
};

template < typename T >
void printList(const std::list< T > &l)
{
	for (typename std::list< T >::const_iterator it = l.begin(); it != l.end(); it++)
	{
		std::cout << *it;
		if (it != --(l.end()))
			std::cout << " ";
	}
	std::cout << std::endl;
}

std::ostream &operator<<(std::ostream &os, const std::pair< unsigned int, unsigned int > &p);

#endif /* *********************************************************** PRINT_H */
