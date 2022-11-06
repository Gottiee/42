#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	public:
	WrongAnimal();
	WrongAnimal(WrongAnimal const &);
	~WrongAnimal();
	WrongAnimal	&operator=(WrongAnimal const &);
	void		makeSound(void) const;
	std::string	getType(void) const;

	protected:
	std::string type;
};

#endif
