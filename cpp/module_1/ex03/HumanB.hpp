#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	public:
	
	HumanB(std::string newName);
	HumanB(std::string newName, Weapon &newWeapon);
	void	attack(void);
	void	setWeapon(Weapon &newWeapon);

	private:

	std::string	name;
	Weapon *weapon;
};

#endif
