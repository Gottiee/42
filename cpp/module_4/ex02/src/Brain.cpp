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
	std::cout << "Default assignement call for Brain" << std::endl;
	for (int i = 0; i < 100; i ++)
		this->ideas[i] = src.getString(i);
	return *this;
}

void	Brain::setIdeas(std::string idea)
{
	int i = 0;
	while (!this->ideas[i].empty())
		i ++;	
	if (i != 100)
		this->ideas[i] = idea;
	else 
		std::cout << "No more place for any idea" << std::endl;
}

void	Brain::printIdea(void)
{
	int i = -1;
	while (!this->ideas[++i].empty())
		std::cout << "Idea number " << i << ":" << this->ideas[i] << std::endl;
}

std::string	*Brain::getStringBrain(void)
{
	return &this->ideas[0];
}

void	Brain::setFullIdeas(std::string idea[100])
{
	int i = -1;
	while (i < 100 && !idea[++i].empty())
		this->ideas[i] = idea[i];
}

std::string	Brain::getString(int i) const
{
	return this->ideas[i];
}
