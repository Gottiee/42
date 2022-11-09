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
	this->_brain = src.copyBrain(src.getStringBrain());
	return *this;
}

void	Dog::makeSound(void) const
{
	std::cout << "WAOUFF" << std::endl;
}

void	Dog::setIdea(std::string idea)
{
	this->_brain->setIdeas(idea);
}

void	Dog::printIdea(void)
{
	this->_brain->printIdea();
}

std::string	*Dog::getStringBrain(void) const
{
	return this->_brain->getStringBrain();
}

Brain	*Dog::copyBrain(std::string	idea[100]) const
{
	Brain *brain = new Brain;
	brain->setFullIdeas(idea);
	return brain;
}
