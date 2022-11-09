#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string>
#include "ICharacter"

class Character: public ICharacter
{

	/*******************/
	/*      CANON      */
	/*******************/

	public:
	Character();
	Character(Character const &src);
	~Character();
	Character	&operator=(Character const &src);

	private:

};

#endif
