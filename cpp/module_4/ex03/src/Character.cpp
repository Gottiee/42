#include "../header/Character.hpp"

Character::Character():_inventaire[0](NULL), _inventaire[1](NULL), _inventaire[2](NULL), _inventaire[3](NULL), _tmp(NULL), name("Noname")
{
	std::cout << "Default constructor call for Character" << std::endl;
}

Character::Character(Character const &src) 
{
	*this = src;
	std::cout << "Copy constructor call for Character" << std::endl;
}

Character::~Character()
{
	std::cout << "Default destuctor call for Character" << std::endl;
}

Character	&Character::operator=(Character const &src)
{
	std::cout << "Default assignement constructor call for Character" << std::endl;
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
	this->tmp = this->_inventaire[idx];
	this->_inventaire[idx] = NULL;
}

void	Character::use(int idx, ICharacter &target)
{
	
}
