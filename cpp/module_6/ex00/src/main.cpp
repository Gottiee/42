#include "../header/Convert.hpp"

int main(int argc, char **argv)
{
	(void)argv;
	if (argc > 2 || argc == 1)
	{
		std::cerr << "Wrong input\n<./convert> <scalar type(int/double/float/char)>\n";
		return 0;
	}
	try
	{
		Convert	convert(argv[1]);
		//convert.shine();
	}
	catch (Convert::Empty &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (Convert::NoneChar &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (Convert::IntPro &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (Convert::DoublePro &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
