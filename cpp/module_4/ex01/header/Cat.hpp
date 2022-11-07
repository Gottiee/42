#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "../header/Brain.hpp"

class Cat: public Animal
{
	public:
	Cat();
	Cat(Cat const &);
	~Cat();
	Cat		&operator=(Cat const &);
	void	makeSound(void) const;

	private:
	Brain	*_brain;
};

#endif
