#include "../header/A.hpp"
#include "../header/B.hpp"
#include "../header/C.hpp"
#include <cstdlib>
#include <ctime>

int	Random(void)
{
	std::srand(std::time(NULL));

	return rand() % 3;	
}

Base *generate(void)
{
	int choice = Random();

	if (choice == 0)
	{
		std::cout << "Generate A class\n\n";
		return (new A);
	}
	if (choice == 1)
	{
		std::cout << "Generate B class\n\n";
		return (new B);
	}
	if (choice == 2)
	{
		std::cout << "Generate C class\n\n";
		return (new C);
	}
	return (NULL);
}

void	identify(Base *p)
{
	Base *res;

	std::cout << "Identify with pointer\n";
	res = dynamic_cast<A *>(p);
	if (res)
	{
		std::cout << "its A class !(from poiner)\n";
		return;
	}
	res = dynamic_cast<B *>(p);
	if (res)
	{
		std::cout << "its B class !(from poiner)\n";
		return;
	}
	res = dynamic_cast<C *>(p);
	if (res)
	{
		std::cout << "its C class !(from poiner)\n";
		return;
	}
}

void	identify(Base &p)
{
	std::cout << "\nIdentify with reference\n";
	try
	{
		A a = dynamic_cast<A &>(p);
		std::cout << "its A class !(from reference)\n";
	}
	catch (std::bad_cast &bc)
	{
	}
	try
	{
		B a = dynamic_cast<B &>(p);
		std::cout << "its B class !(from reference)\n";
	}
	catch (std::bad_cast &bc)
	{
	}
	try
	{
		C a = dynamic_cast<C &>(p);
		std::cout << "its C class !(from reference)\n";
	}
	catch (std::bad_cast &bc)
	{
	}
}

int main(void)
{
	Base	*base;
	base = generate();
	identify(base);
	identify(*base);
	delete base;
}
