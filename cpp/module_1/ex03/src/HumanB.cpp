#include "../HumanB.hpp"

HumanB::HumanB(std::string newName, Weapon newWeapon):name(newName)
{
	std::cout << "Human B creer avec l'arme: ";
	this->weapon = newWeapon;
	std::cout << this->weapon.getType() << std::endl;
}

HumanB::HumanB(std::string newName):name(newName)
{
	std::cout << "Human B creer sans arme" << std::endl;
}

void	HumanB::setWeapon(Weapon newWeapon)
{
	this->weapon = newWeapon;
}

void	HumanB::attack()
{
		std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}
