#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
	public:	

	Weapon();
	Weapon(std::string newWeapon);
	const std::string	&getType(void);
	void				setType(std::string str);

	private:

	std::string 		type;
};

#endif
