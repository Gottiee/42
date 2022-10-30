#include "../header/ClapTrap.hpp"

int main(void)
{
	ClapTrap boby("boby");
	std::cout << boby;
	boby.attack("chaussette");
	boby.takeDamage(5);
	std::cout << boby;
	boby.beRepaired(3);
	std::cout << boby;
	boby.takeDamage(8);
	boby.attack("kek");
}
