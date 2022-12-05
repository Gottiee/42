#include "../header/AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "Default constructor call for AMateria" << std::endl;
}

AMateria::AMateria(std::string const &type): _type(type)
{
	std::cout << "Set type constructor call for AMateria" << std::endl;
}

AMateria::AMateria(AMateria const &src)
{
	*this = src;
	std::cout << "Copy constructor call for AMateria" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "Default destuctor call for AMateria" << std::endl;
}

AMateria	&AMateria::operator=(AMateria const &src)
{
	std::cout << "Default assignement call for AMateria" << std::endl;	
	this->_type = src.getType();
	return *this;
}

std::string	const &AMateria::getType(void) const
{
	return this->_type;
}

void	AMateria::use(ICharacter& target)
{
	(void)target;
}
