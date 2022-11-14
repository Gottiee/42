#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include <string>
#include "AMateria.hpp"

class Ice: public AMateria
{

	/*******************/
	/*      CANON      */
	/*******************/

	public:
	Ice();
	Ice(Ice const &src);
	~Ice();
	Ice			&operator=(Ice const &src);
	AMateria	*clone() const;
	void		setType(std::string type);
	void		use(ICharacter &target);

	private:

};

#endif
