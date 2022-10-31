#include "../header/ScavTrap.hpp"
#include "../header/FragTrap.hpp"

int main(void)
{
	FragTrap frag("frag");
	std::cout << frag;
	frag.attack("chaussette");
	frag.takeDamage(5);
	std::cout << frag;
	frag.beRepaired(3);
	std::cout << frag;
	frag.takeDamage(8);
	frag.attack("kek");
	frag.highFivesGuys();
	std::cout << frag;
	frag.takeDamage(90);
	std::cout << frag;
	frag.attack("kek");

	std::cout << std::endl;

	ClapTrap clap("clap");
	std::cout << clap;

	std::cout << std::endl;

	ScavTrap scav("scav");
	std::cout << scav;
}
