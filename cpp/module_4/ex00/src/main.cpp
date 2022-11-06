#include "../header/Cat.hpp"
#include "../header/Dog.hpp"
#include "../header/WrongCat.hpp"

int main()
{
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " ";
		j->makeSound();
		std::cout << i->getType() << " ";
		i->makeSound();
		meta->makeSound();
		delete(meta);
		delete(j);
		delete(i);
	}
	std::cout << std::endl;
	{
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* i = new WrongCat();
		std::cout << i->getType() << " ";
		i->makeSound(); //will not output the cat sound!
		meta->makeSound();
		delete(meta);
		delete(i);
	}
}
