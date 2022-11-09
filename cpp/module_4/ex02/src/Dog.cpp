#include "../header/Dog.hpp"

Dog::Dog()
{
	std::cout << "Default constructor call for Dog" << std::endl;
	this->_brain = new Brain();
	this->type = "dog";
}

Dog::Dog(Dog const &src): Animal()
{
	std::cout << "Copy constructor call for Dog" << std::endl;
	*this = src;
}

Dog::~Dog()
{
	std::cout << "Default destructor call for Dog" << std::endl;
	delete this->_brain;
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
