#include "../header/DiamondTrap.hpp"

int main(void)
{
	{
		DiamondTrap frag("frag");
		std::cout << frag;
		frag.attack("chaussette");
		std::cout << frag;
		frag.guardGate();
		std::cout << frag;
		frag.takeDamage(8);
		std::cout << frag;
		frag.highFivesGuys();
		std::cout << frag;
		frag.whoAmI();
	}
	std::cout << std::endl;
	{
		ClapTrap clap("clap");
		std::cout << clap;
	}
	std::cout << std::endl;
	{
		ScavTrap scav("scav");
		std::cout << scav;
	}
	std::cout << std::endl;
	{
		FragTrap frag("frag");
		std::cout << frag;
	}
}
