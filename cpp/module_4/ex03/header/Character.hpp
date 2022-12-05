#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character: public ICharacter
{

	/*******************/
	/*      CANON      */
	/*******************/

	public:
	Character();
	Character(Character const &src);
	~Character();
	Character			&operator=(Character const &src);
	std::string const	&getName(void) const;
	void				equip(AMateria *m);
	void				unequip(int idx);
	void				use(int idx, ICharacter	&target);

	private:
	AMateria	*_inventaire[4];
	AMateria	*_tmp;
	std::string	_name;
};

#endif
