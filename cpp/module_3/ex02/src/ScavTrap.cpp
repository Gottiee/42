#include "../header/ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << this->_name << " constructed from ScavTrap" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src)
{
	std::cout << this->_name << " constructed from ScavTrap" << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap()
{
	std::cout << this->_name << " destructed from ScavTrap" << std::endl;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &src)
{
	this->_hit = src.getHit();
	this->_name = src.getName();
	this->_energy = src.getEnergy();
	this->_damageAttack = src.getDamage();
	this->_gateKeeper = src.getGateKeeper();
	return *this;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name), _gateKeeper(false)
{
	this->_hit = 100;
	this->_energy = 50;
	this->_damageAttack = 20;
	std::cout << this->_name << " constructed from ScavTrap" << std::endl;
}

void	ScavTrap::guardGate()
{
	if (this->_gateKeeper)
	{
		std::cout << this->_name << " is already in mode Gate KEEPER" << std::endl;
		return ;
	}
	std::cout << this->_name << " ScavTrap is now in mode Gate KEEPER" << std::endl;
	this->_gateKeeper = true;
}

std::ostream	&operator<<(std::ostream &out, ScavTrap const &src)
{
	out << "ScavTrap " << src.getName() << " has: " << src.getHit() << " life points, " << src.getEnergy() << " energy, can deal: " << src.getDamage() << " damage";
	if (src.getGateKeeper())	
		std::cout << " ,and protected the gate";
	else
		std::cout << " ,and don't protect the gate";
	std::cout << std::endl;
	return out;
}

bool	ScavTrap::getGateKeeper() const
{
	if (this->_gateKeeper)
		return true;
	return false;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_hit <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " is dead and can't attack" << std::endl;
		return ;
	}
	if (this->_energy <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " doesn't have enought energy to attack... " << std::endl;
		return ;
	}
	this->_energy --;
	std::cout << "ScavTrap " << this->_name << " attacks ";
	std::cout << target << ", causing " << this->_damageAttack;
	std::cout << " points of damage!" << std::endl;
}
