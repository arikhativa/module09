#ifndef JACOBSTHAL_HPP
#define JACOBSTHAL_HPP

#include <iostream>

class Jacobsthal
{
  public:
	~Jacobsthal();
	static ::size_t getIndex(::size_t i);

  private:
	Jacobsthal();
	Jacobsthal &operator=(Jacobsthal const &rhs);
	Jacobsthal(Jacobsthal const &src);
};

#endif /* ****************************************************** JACOBSTHAL_H */
