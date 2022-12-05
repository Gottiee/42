#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include <string>
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource: public IMateriaSource
{

	/*******************/
	/*      CANON      */
	/*******************/

	public:
	MateriaSource();
	MateriaSource(MateriaSource const &src);
	~MateriaSource();
	MateriaSource	&operator=(MateriaSource const &src);
	void			learnMateria(AMateria *src);
	AMateria		*createMateria(std::string const &type);

	private:
	AMateria	*_inv[4];
};

#endif
