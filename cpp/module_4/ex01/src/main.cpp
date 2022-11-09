#include "../header/Cat.hpp"
#include "../header/Dog.hpp"

int main(void)
{
	std::cout << "-------Leak and constructor test--------" << std::endl << std::endl;
	{
		Animal *animal[4];
		for (int i = 0; i < 4 ; i ++)
		{
			if (i % 2 == 0)
				animal[i] = new Cat;
			else
				animal[i] = new Dog;
			std::cout << std::endl;
		}
		for(int i = 0; i < 4; i++)
		{
			delete animal[i];
			std::cout << std::endl;
		}
	}
	std::cout << "-------Set Idea test-------" << std::endl << std::endl;
	{
		Cat	cat;
		std::cout << std::endl;
		cat.setIdea("Wow");
		cat.setIdea("Huge");
		cat.printIdea();
		std::cout << std::endl;
	}
	std::cout << std::endl << "-------Deep copy test-------" << std::endl << std::endl;
	{
		Cat	cat;
		std::cout << std::endl;
		cat.setIdea("Wow");
		cat.setIdea("Huge");
		std::cout << "cat idea" << std::endl;
		cat.printIdea();
		std::cout << std::endl;	
		Cat cat_cp = cat;
		std::cout << std::endl;
		std::cout << "cat_cp idea" << std::endl;
		cat_cp.printIdea();
		std::cout << std::endl;
		std::cout << "I add an idea to cat_cp and cat shouldn't have this idea" << std::endl;
		cat_cp.setIdea("normal cat shouldn't see that");
		std::cout << "cat_cp idea" << std::endl;
		cat_cp.printIdea();
		std::cout << std::endl;
		std::cout << "cat idea" << std::endl;
		cat.printIdea();
		std::cout << std::endl;	
	}
}
