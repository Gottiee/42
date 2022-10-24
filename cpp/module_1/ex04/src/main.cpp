#include "../include/main.hpp"

int open_files(std::ifstream &ifs, std::ofstream &ofs, char **argv)
{
	std::string		replace(argv[1]);

	replace += ".replace";
	ifs.open(argv[1]);
	if (ifs.fail())
	{
		std::perror("Error");
		return (1);
	}
	ofs.open(replace.c_str());
	if (ofs.fail())
	{
		std::perror("Error");
		return (1);
	}
	return (0);
}

void	print_info(int argc)
{
	if (argc < 4 || argc > 4)
	{
		std::cout << "# Create a <filename.replace> wich remplace every occurence of string1 per string2 in <filename> #" << std::endl << std::endl;
		std::cout << "> ./sed <filename> <string1> <string2>" << std::endl;
		exit(1);
	}
}

std::string	read_file(std::ifstream &file)
{
	std::stringstream	buffer;	
	std::string			str;

	buffer << file.rdbuf();
	str = buffer.str();
	return (str);
}

std::string	swap_char_str(std::string str, char *init, char *replace)
{
	long unsigned int	i = 0;
	long unsigned int	k = 0;
	std::string 		out;		

	while (i < str.length())
	{
		i = str.find(init, i);
		if (i == std::string::npos)
			break;
		while (k < i)
		{
			out += str[k];
			k ++;
		}
		out += replace;
		k += strlen(init);
		i += strlen(init);
	}
	while (k < str.length())
	{
		out += str[k];
		k ++;
	}
	return (out);
}

int main(int argc, char **argv)
{
	print_info(argc);

	std::ifstream	file;
	std::ofstream	file_replace;
	std::string		file_in;
	std::string		file_out;

	if (open_files(file, file_replace, argv) == 1)
		return (1);
	file_in = read_file(file);
	file_out = swap_char_str(file_in, argv[2], argv[3]);
	file_replace << file_out;
	file.close();
	file_replace.close();
}
