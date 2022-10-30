#include "../header/ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << this->_name << " constructed" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
	*this = src;
}

ClapTrap::~ClapTrap()
{
	std::cout << this->_name << " destructed" << std::endl;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &src)
{
	this->_hit = src.getHit();
	this->_name = src.getName();
	this->_energy = src.getEnergy();
	this->_damageAttack = src.getDamage();
	return *this;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hit(10), _energy(10), _damageAttack(0)
{
	std::cout << this->_name << " constructed" << std::endl;
}

int	ClapTrap::getHit(void) const
{
	return this->_hit;
}

std::string ClapTrap::getName(void) const
{
	return this->_name;
}

int ClapTrap::getEnergy() const
{
	return this->_energy;	
}

int ClapTrap::getDamage(void) const
{
	return this->_damageAttack;
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->_hit <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is dead and can't attack" << std::endl;
		return ;
	}
	if (this->_energy <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " doesn't have enought energy to attack... " << std::endl;
		return ;
	}
	this->_energy --;
	std::cout << "ClapTrap " << this->_name << " attacks ";
	std::cout << target << ", causing " << this->_damageAttack;
	std::cout << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is dead and can't be attack" << std::endl;
		return ;
	}
	this->_hit -= amount;
	if (this->_hit <= 0)
	{
		std::cout << "ClapTrap " << this->_name << "took " << amount << " damage and trepassed..." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " tooked " << amount;
	std::cout << " damages and still have: " << this->_hit << " life points" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hit <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is dead and can't be repaired" << std::endl;
		return ;
	}
	if (this->_energy <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " doesn't have enought energy to be repaired... " << std::endl;
		return ;
	}
	this->_energy --;
	this->_hit += amount;
	std::cout << "ClapTrap " << this->_name << " be repaired and now have: ";
	std::cout << this->_hit << " life points" << std::endl;
}


std::ostream	&operator<<(std::ostream &out, ClapTrap const &src)
{
	out << "ClapTrap " << src.getName() << " has: " << src.getHit() << " life points, " << src.getEnergy() << " energy, and can deal: " << src.getDamage() << " damage" << std::endl;
	return out;
}
