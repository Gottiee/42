#include "../header/Character.hpp"

Character::Character()
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
