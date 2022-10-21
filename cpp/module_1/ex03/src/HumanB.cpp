#include "../HumanB.hpp"


HumanB::HumanB(std::string newName):name(newName), weapon(NULL)
{
	std::cout << "Human B(" << this->name << ") creer sans arme" << std::endl;
}

HumanB::HumanB(std::string newName, Weapon &newWeapon):name(newName), weapon(&newWeapon)
{
		std::cout << "Human B(" << this->name <<")  creer avec l'arme: ";
		std::cout << this->weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &newWeapon)
{
	this->weapon = &newWeapon;
}

void	HumanB::attack()
{
		std::cout << this->name << " attacks with their "; 
		if (this->weapon)
			std::cout << this->weapon->getType() << std::endl;
		else
			std::cout << "hands" << std::endl;
}
