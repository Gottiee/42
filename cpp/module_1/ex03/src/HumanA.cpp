#include "../HumanA.hpp"

HumanA::HumanA(std::string newName, Weapon &newWeapon):name(newName), weapon(newWeapon)
{
	std::cout << "Human B creer avec l'arme: ";
	std::cout << this->weapon.getType() << std::endl;
}

void	HumanA::attack()
{
		std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}
