#include "../header/Dog.hpp"

Dog::Dog()
{
	std::cout << "Default constructor call for Dog" << std::endl;
	this->type = "dog";
}

Dog::Dog(Dog const &src)
{
	std::cout << "Copy constructor call for Dog" << std::endl;
	*this = src;
}

Dog::~Dog()
{
	std::cout << "Default destructor call for Dog" << std::endl;
}

Dog	&Dog::operator=(Dog const &src)
{
	this->type = src.getType();
	return *this;
}

void	Dog::makeSound(void) const
{
	std::cout << "WAOUFF" << std::endl;
}
