#include "../header/iter.hpp"

int main(void)
{
	char test[4];
	std::cout << "---Char[]---\n\n";
	for (int i = 0; i < 4; i ++)
	{
		test[i] = '1';
		std::cout << "index: " << i << " = \"" << test[i] << "\"" << std::endl;
	}
	std::cout << "\nFonction iter call\n\n";
	iter(test, 4, print);
}
