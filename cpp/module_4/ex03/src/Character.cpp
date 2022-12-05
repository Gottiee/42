#include "../header/Character.hpp"
#include "../header/Cure.hpp"
#include "../header/Ice.hpp"

Character::Character():_tmp(NULL), _name("Noname")
{
	this->_inventaire[0] = NULL;
	this->_inventaire[1] = NULL;
	this->_inventaire[2] = NULL;
	this->_inventaire[3] = NULL;
	std::cout << "Default constructor call for Character" << std::endl;
}

Character::Character(std::string name):_tmp(NULL), _name(name)
{
	this->_inventaire[0] = NULL;
	this->_inventaire[1] = NULL;
	this->_inventaire[2] = NULL;
	this->_inventaire[3] = NULL;
	std::cout << "Name constructor call for Character" << std::endl;
}

Character::Character(Character const &src) 
{
	*this = src;
	std::cout << "Copy constructor call for Character" << std::endl;
}

Character::~Character()
{
	for (int i = 0; i < 4; i ++)
	{
		if (this->_inventaire[i])
			delete this->_inventaire[i];
	}
	if (this->_tmp)
		delete this->_tmp;
	std::cout << "Default destuctor call for Character" << std::endl;
}

Character	&Character::operator=(Character const &src)
{
	AMateria	*new_ma[4];

	std::cout << "Default assignement constructor call for Character" << std::endl;
	this->_name = src.getName();
	this->_tmp = src.getTmp();
	for (int j = 0; j < 4; j++)
	{
		if (src._inventaire[j]->getType() == "cure")
			new_ma[j] = new Cure;
		else if (src._inventaire[j]->getType() == "ice")
			new_ma[j] = new Ice;
		this->_inventaire[j] = new_ma[j];
		delete src._inventaire[j];
	}
	return *this;
}

std::string const &Character::getName() const
{
	return this->_name;
}

void	Character::equip(AMateria *m)
{
	int i = -1;	
	while (++i < 4 && this->_inventaire[i]);
	if (i == 4)
		return ;
	this->_inventaire[i] = m;
}

void	Character::unequip(int idx)
{
	if (idx > 4 || !this->_inventaire[idx])
		return ;
	if (this->_tmp)
		delete this->_tmp;
	this->_tmp = this->_inventaire[idx];
	this->_inventaire[idx] = NULL;
}

void	Character::use(int i, ICharacter &target)
{
	if (this->_inventaire[i])
		this->_inventaire[i]->use(target);
}

AMateria	*Character::getTmp() const
{
	return this->_tmp;	
}
