#include "../header/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("metamorphe")
{
	std::cout << "Default constructor call for WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src)
{
	std::cout << "Copy constructor call for WrongAnimal" << std::endl;
	*this = src;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Default destructor call for WrongAnimal" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &src)
{
	this->type = src.getType();
	return *this;
}

std::string	WrongAnimal::getType(void) const
{
	return (this->type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "Im a Wrong Animal" << std::endl;
}
