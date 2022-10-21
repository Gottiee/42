#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	public:
	
	HumanA(std::string newName, Weapon &newWeapon);
	void	attack(void);

	private:

	std::string	name;
	Weapon &weapon;
};

#endif
