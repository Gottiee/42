#include "../header/RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: too many or to much arguments\n";
		return 1;
	}
	try
	{
		RPN calcul(argv[1]);
	}
	catch (std::exception &e)
	{
	}
}
