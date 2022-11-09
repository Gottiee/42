#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include <string>
#include "AMateria.hpp"

class Cure: public AMateria
{

	/*******************/
	/*      CANON      */
	/*******************/

	public:
	Cure();
	Cure(Cure const &src);
	~Cure();
	Cure		&operator=(Cure const &src);
	AMateria	*clone() const;
	void		setType(std::string type);

	private:

};

#endif
