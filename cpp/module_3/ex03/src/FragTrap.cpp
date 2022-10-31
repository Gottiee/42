#include "../header/FragTrap.hpp"

int FragTrap::hitPointsInit = 100;
int FragTrap::energyPointsInit = 100;
int FragTrap::attackDamageInit = 30;

FragTrap::FragTrap()
{
	this->_hit = 100;
	this->_energy = 100;
	this->_damageAttack = 30;
	std::cout << this->_name << " default constructor from FragTrap" << std::endl;
}

FragTrap::FragTrap(FragTrap const &src)
{
	std::cout << this->_name << " constructed from FragTrap" << std::endl;
	*this = src;
}

FragTrap::~FragTrap()
{
	std::cout << this->_name << " destructed from FragTrap" << std::endl;
}

FragTrap	&FragTrap::operator=(FragTrap const &src)
{
	this->_hit = src.getHit();
	this->_name = src.getName();
	this->_energy = src.getEnergy();
	this->_damageAttack = src.getDamage();
	return *this;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->_hit = 100;
	this->_energy = 100;
	this->_damageAttack = 30;
	std::cout << this->_name << " name constructor from FragTrap" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::string user;
	std::cout << "High Five Guys ! (\"yes\" if u want)" << std::endl;
	std::cin >> user;
	if (user != "yes")
	{
		std::cout << "ah... ok it doesn't matter" << std::endl;
		return ;
	}
	else
		std::cout << "CLAP" << std::endl;
	this->_energy --;
}
