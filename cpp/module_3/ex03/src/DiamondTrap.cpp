#include "../header/DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << this->_name << " default constructor from DiamondTrap" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &src):ClapTrap(), FragTrap(), ScavTrap()
{
	std::cout << this->_name << " copy constructor from DiamondTrap" << std::endl;
	*this = src;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << this->_name << " destructed from DiamondTrap" << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(DiamondTrap const &src)
{
	this->_hit = src.getHit();
	this->_name = src.getName();
	this->_energy = src.getEnergy();
	this->_damageAttack = src.getDamage();
	this->_gateKeeper = src.getGateKeeper();
	return *this;
}

DiamondTrap::DiamondTrap(std::string name)
{
	this->_name = name;
	ClapTrap::_name = name + "_clap_name";
	this->_gateKeeper = false;
	this->_name = name;
	this->_hit = FragTrap::hitPointsInit;
	this->_energy = ScavTrap::energyPointsInit;
	this->_damageAttack = FragTrap::attackDamageInit;
	std::cout << this->_name << " name constructor from DiamondTrap" << std::endl;
}

std::ostream	&operator<<(std::ostream &out, DiamondTrap const &src)
{
	out << "DiamondTrap " << src.getName() << " has: " << src.getHit() << " life points, " << src.getEnergy() << " energy, can deal: " << src.getDamage() << " damage";
	if (src.getGateKeeper())	
		std::cout << " ,and protected the gate";
	else
		std::cout << " ,and don't protect the gate";
	std::cout << std::endl;
	return out;
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap name= " << this->_name << " and ClapTrap name= " << ClapTrap::_name << std::endl;
}

std::string	DiamondTrap::getName(void) const
{
	return this->_name;
}
