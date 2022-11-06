#ifndef DOG_HPP
#define DOG_HPP

#include "../header/Animal.hpp"

class Dog: public Animal
{
	public:
	Dog();
	Dog(Dog const &);
	~Dog();
	Dog	&operator=(Dog const &);
	void	makeSound(void) const;
};

#endif
