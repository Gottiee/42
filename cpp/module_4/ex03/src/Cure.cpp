#include "../header/Cure.hpp"

Cure::Cure(): AMateria("cure")
{
	std::cout << "Default constructor call for Cure" << std::endl;
}

Cure::Cure(Cure const &src): AMateria("cure")
{
	*this = src;
	std::cout << "Copy constructor call for Cure" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Default destuctor call for Cure" << std::endl;
}

Cure	&Cure::operator=(Cure const &src)
{
	std::cout << "Default assignement constructor call for Cure" << std::endl;
	this->_type = src.getType();
	return *this;

}

AMateria	*Cure::clone() const
{
	AMateria *materia;
	materia = new Cure;
	materia->setType(this->getType());
	return materia;
}

void	Cure::setType(std::string type)
{
	this->_type	= type;
}
