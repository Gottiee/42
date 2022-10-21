#include "../include/main.hpp"

int open_files(std::ifstream &ifs, std::ofstream &ofs, char **argv)
{
	std::string		replace(argv[1]);
	replace += ".replace";
	std::ifstream	ifs(argv[1]);
	if (ifs.fail())
	{
		std::perror("Error");
		return (1);
	}
	std::ofstream	ofs(replace.c_str());
	if (ofs.fail())
	{
		std::perror("Error");
		return (1);
	}
	return (0);
}



int main(int argc, char **argv)
{
	if (argc < 4 || argc > 4)
	{
		std::cout << "# Create a <filename.replace> wich remplace every occurence of string1 per string2 in <filename> #" << std::endl << std::endl;
		std::cout << "> ./sed <filename> <string1> <string2>" << std::endl;
		return (0);
	}

	std::ifstream	file;
	std::ofstream	file_replace;
	if (open_files(file, file_replace, argv) == 1)
		return (1);

	ifs.close();
	ofs.close();
}
