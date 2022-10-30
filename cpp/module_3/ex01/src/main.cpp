#include "../header/ScavTrap.hpp"

int main(void)
{
	ScavTrap boby("boby");
	std::cout << boby;
	boby.attack("chaussette");
	boby.takeDamage(5);
	std::cout << boby;
	boby.beRepaired(3);
	std::cout << boby;
	boby.takeDamage(8);
	boby.attack("kek");
	boby.guardGate();
	std::cout << boby;
	boby.takeDamage(90);
	std::cout << boby;
	boby.attack("kek");

	ClapTrap clap("clap");
	std::cout << clap;
}
