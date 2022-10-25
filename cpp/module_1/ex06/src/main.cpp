#include "../include/main.hpp"

int main(int argc, char **argv)
{
	Harl	instance;

	if (argc != 2)
	{
		std::cout << "./HarlFilter <INSTRUCTION>" << std::endl;
		return (1);
	}
	instance.complain(argv[1]);
}
