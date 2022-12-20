#include "../header/Convert.hpp"

int main(int argc, char **argv)
{
	(void)argv;
	if (argc > 2 || argc == 1)
	{
		std::cerr << "Wrong input\n<./convert> <scalar type(int/double/float/char)>\n";
	}

	try
	{
		Convert	convert(argv[1]);
		convert.shine();
	}
	catch
	{
	
	}
}
