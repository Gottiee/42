#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	public:
	Animal();
	Animal(Animal const &);
	virtual ~Animal();
	Animal			&operator=(Animal const &);
	virtual void	makeSound(void) const = 0;
	std::string		getType(void) const;

	protected:
	std::string type;
};

#endif
