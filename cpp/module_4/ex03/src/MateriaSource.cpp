#include "../header/MateriaSource.hpp"
#include "../header/Cure.hpp"
#include "../header/Ice.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "Default constructor call for MateriaSource" << std::endl;
	this->_inv[0] = NULL;
	this->_inv[1] = NULL;
	this->_inv[2] = NULL;
	this->_inv[3] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &src)
{
	*this = src;
	std::cout << "Copy constructor call for MateriaSource" << std::endl;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i ++)
	{
		if (this->_inv[i])
			delete this->_inv[i];
	}
	std::cout << "Default destuctor call for MateriaSource" << std::endl;
}

MateriaSource	&MateriaSource::operator=(MateriaSource const &src)
{
	std::cout << "Default assignement call for MateriaSource" << std::endl;
	for (int j = 0; j < 4; j++)
		this->_inv[j] = src._inv[j];	
	return *this;
}

void	MateriaSource::learnMateria(AMateria *src)
{
	int i = -1;	

	while (++i < 4)
	{
		if (!this->_inv[i])
		{
			this->_inv[i] = src;
			break ;
		}
	}
	if (i == 4)
		std::cout << "No more place in AMateria inventory" << std::endl;
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	int			 i = -1;
	AMateria	 *new_ma = NULL;

	while (this->_inv[++i] && (i < 4 && this->_inv[i]->getType() != type));
	if (i == 4)
		return (NULL);
	if (this->_inv[i] && this->_inv[i]->getType() == "cure")
		new_ma = new Cure;
	else if (this->_inv[i] && this->_inv[i]->getType() == "ice")
		new_ma = new Ice;
	return (new_ma);
}
