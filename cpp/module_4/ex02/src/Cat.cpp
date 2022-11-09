#include "../header/Cat.hpp"

Cat::Cat()
{
	std::cout << "Default constructor call for Cat" << std::endl;
	this->_brain = new Brain();
	this->type = "cat";
}

Cat::Cat(Cat const &src) : Animal()
{
	std::cout << "Copy constructor call for Cat" << std::endl;
	*this = src;
}

Cat::~Cat()
{
	std::cout << "Default destructor call for Cat" << std::endl;
	delete this->_brain;
}

Cat	&Cat::operator=(Cat const &src)
{
	this->type = src.getType();
	this->_brain = src.copyBrain(src.getStringBrain());
	return *this;
}

void	Cat::makeSound(void) const
{
	std::cout << "MIAOOUUUUUU" << std::endl;
}

void	Cat::setIdea(std::string idea)
{
	this->_brain->setIdeas(idea);
}

void	Cat::printIdea(void)
{
	this->_brain->printIdea();
}

std::string	*Cat::getStringBrain(void) const
{
	return this->_brain->getStringBrain();
}

Brain	*Cat::copyBrain(std::string	idea[100]) const
{
	Brain *brain = new Brain;
	brain->setFullIdeas(idea);
	return brain;
}
