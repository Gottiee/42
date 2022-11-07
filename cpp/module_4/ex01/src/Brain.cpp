#include "../header/Brain.hpp"

Brain::Brain()
{
	std::cout << "Default constructor call for Brain" << std::endl;
}

Brain::Brain(Brain const &src)
{
	*this = src;
	std::cout << "Copy constructor call for Brain" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Default destuctor call for Brain" << std::endl;
}

Brain	&Brain::operator=(Brain const &src)
{
	(void)src;
	std::cout << "Default assignement call for Brain" << std::endl;
	return *this;
}
