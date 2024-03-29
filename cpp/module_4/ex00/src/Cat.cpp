#include "../header/Cat.hpp"

Cat::Cat()
{
	std::cout << "Default constructor call for Cat" << std::endl;
	this->type = "cat";
}

Cat::Cat(Cat const &src): Animal()
{
	std::cout << "Copy constructor call for Cat" << std::endl;
	*this = src;
}

Cat::~Cat()
{
	std::cout << "Default destructor call for Cat" << std::endl;
}

Cat	&Cat::operator=(Cat const &src)
{
	this->type = src.getType();
	return *this;
}

void	Cat::makeSound(void) const
{
	std::cout << "MIAOOUUUUUU" << std::endl;
}
