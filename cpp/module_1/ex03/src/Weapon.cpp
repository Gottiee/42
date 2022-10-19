#include "../Weapon.hpp"

Weapon::Weapon(void)
{

}

Weapon::Weapon(std::string newWeapon): type(newWeapon)
{	

}

const std::string	&Weapon::getType(void)
{
	return (this->type);
}

void	Weapon::setType(std::string str)
{
	this->type = str;
}
