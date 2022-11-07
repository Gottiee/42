#include "../header/Animal.hpp"

Animal::Animal()
{
	std::cout << "Default constructor call for Animal" << std::endl;
	this->type = "Metamorphe";
}

Animal::Animal(Animal const &src)
{
	std::cout << "Copy constructor call for Animal" << std::endl;
	*this = src;
}

Animal::~Animal()
{
	std::cout << "Default destructor call for Animal" << std::endl;
}

Animal	&Animal::operator=(Animal const &src)
{
	this->type = src.getType();
	return *this;
}


std::string	Animal::getType(void) const
{
	return (this->type);
}

void	Animal::makeSound(void) const
{
	std::cout << "What am i suppose to do ?" << std::endl;
}
