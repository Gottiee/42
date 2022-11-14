#include "../header/Ice.hpp"

Ice::Ice(): AMateria("ice")
{
	std::cout << "Default constructor call for Ice" << std::endl;
}

Ice::Ice(Ice const &src): AMateria("ice")
{
	*this = src;
	std::cout << "Copy constructor call for Ice" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Default destuctor call for Ice" << std::endl;
}

Ice	&Ice::operator=(Ice const &src)
{
	std::cout << "Default assignement constructor call for Ice" << std::endl;
	this->_type = src.getType();
	return *this;
}

AMateria	*Ice::clone() const
{
	AMateria *materia;
	materia = new Ice;
	materia->setType(this->getType());
	return materia;
}

void	Ice::setType(std::string type)
{
	this->_type	= type;
}

void	Ice::use(ICharacter &target)
{
	std::cout << "*shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
