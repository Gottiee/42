#ifndef AMATERIA_HPP
#define AMATERIA_HPP

class AMateria;
#include "ICharacter.hpp"
#include <iostream>
#include <string>

class AMateria
{

	/*******************/
	/*      CANON      */
	/*******************/

	public:
	AMateria();
	AMateria(std::string const &type);
	AMateria(AMateria const &src);
	virtual ~AMateria();

	AMateria			&operator=(AMateria const &src);
	std::string	const	&getType(void) const;
	virtual AMateria	*clone() const = 0;
	virtual void		use(ICharacter &target);
	virtual void		setType(std::string type) = 0;

	protected:
	std::string _type;

};

#endif
