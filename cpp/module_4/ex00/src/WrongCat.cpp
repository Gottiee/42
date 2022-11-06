#include "../header/WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "Default constructor call for WrongCat" << std::endl;
}

WrongCat::WrongCat(WrongCat const &src)
{
	std::cout << "Copy constructor call for WrongCat" << std::endl;
	*this = src;
}

WrongCat::~WrongCat()
{
	std::cout << "Default destructor call for WrongCat" << std::endl;
}

WrongCat	&WrongCat::operator=(WrongCat const &src)
{
	this->type = src.getType();
	return *this;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "TU NE DOIS JAMAIS VOIR CELA" << std::endl;
}
