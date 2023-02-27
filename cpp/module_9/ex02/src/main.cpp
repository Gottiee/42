#include "../header/PmergeMe.hpp"

int main(int argc, char **argv)
{
	std::vector<unsigned int> vec;

	if (argc < 2)
	{
		std::cerr << "To many arguments\n";
		return 2;
	}
	try
	{
		int i = 0;
		while(argv[++i])
			vec.push_back(pars_numb(argv[i]));
		PmergeMe sort(vec);
	}
	catch (std::exception &e) 
	{
	}
}
