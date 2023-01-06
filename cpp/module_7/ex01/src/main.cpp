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
	std::cout << "\nFonction iter call:\n";
	iter(test, 4, print<char>);

	std::cout << "\n---Float[]---\n\n";
	float flo[4];
	for (int i = 0; i < 4; i ++)
	{
		flo[i] = 1.34;
		std::cout << "index: " << i << " = \"" << flo[i] << "\"" << std::endl;
	}
	iter(flo, 4, print<float>);
}
