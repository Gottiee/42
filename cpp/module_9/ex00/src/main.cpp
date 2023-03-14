#include "../header/BitcoinExchange.hpp"
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <exception>

void	fill_csv(std::string str, multimap &map)
{
	int 			find = str.find(",");
	std::list<int>	list;
	double			res;

	std::string left(str.begin(), str.begin() + find);
	list.push_back(std::atoi(left.substr(0, 4).c_str()));
	list.push_back(std::atoi(left.substr(5, 2).c_str()));
	list.push_back(std::atoi(left.substr(8, 2).c_str()));
	std::string	right(str.begin() + find + 1, str.end());
	res = std::atof(right.c_str());
	std::pair<std::list<int>, double>	pair(list, res);
	map.insert(pair);
}

bool	pars_date(std::string date)
{
	std::string	tmp;
	int			i = -1;
	int			res;

	while (date[++i] && i < 4)
	{
		if (!isdigit(date[i]))
			return false;
	}
	if (!date[i] || date[i] != '-')
		return false;
	while (date[++i] && i < 7)
	{
		if (!isdigit(date[i]))
			return false;
		tmp.push_back(date[i]);
	}
	res = std::atoi(tmp.c_str());
	if ( res > 12 || res < 1)
		return false;
	tmp.clear();
	if (!date[i] || date[i] != '-')
		return false;
	while (date[++i])
	{
		if (!isdigit(date[i]))
			return false;
		tmp.push_back(date[i]);
	}
	res = std::atoi(tmp.c_str());
	if ( res > 31 || res < 1)
		return false;
	return true;
}

bool	fill_arg(std::string str, BitcoinExchange *bit)
{
	size_t 			find = str.find("|");
	size_t			space = str.find(" ");
	size_t			end = str.rfind(" ");
	std::list<int>	list;
	double			res;

	if (find == std::string::npos)	
	{
		std::cerr << "Error: bad input => " << str << std::endl;
		return false;
	}
	if (space == std::string::npos || space != find - 1)	
	{
		std::cerr << "Error: bad input => " << str << std::endl;
		return false;
	}
	if (end == std::string::npos || end != find + 1)	
	{
		std::cerr << "Error: bad input => " << str << std::endl;
		return false;
	}
	std::string left(str.begin(), str.begin() + space);
	std::string	right(str.begin() + end + 1, str.end());
	res = std::atof(right.c_str());
	if (res < 0)
	{
	
		std::cerr << "Error: not a positive number.\n";
		return false;
	}
	if (res > 1000)
	{
	
		std::cerr << "Error: too large a number.\n";
		return false;
	}
	if (!pars_date(left))
	{
		std::cerr << "Error: bad input => " << str << std::endl;
		return false;
	}
	list.push_back(std::atoi(left.substr(0, 4).c_str()));
	list.push_back(std::atoi(left.substr(5, 2).c_str()));
	list.push_back(std::atoi(left.substr(8, 2).c_str()));
	bit->set_list(list);
	bit->set_nbr(res);
	return true;
}

void	 fill_into_map(std::string str, bool bolo, multimap &map, BitcoinExchange *bit)
{
	std::fstream			fd;
	std::string				tmp_buf;
	bool					start = true;

	fd.open(str.c_str(), std::ios::in);
	if (!fd.is_open())
	{
		std::perror("Txt file problem");
		throw std::exception();
	}
	while (getline(fd, tmp_buf))
	{
		if (start)
		{
			start = false;
			continue ;
		}
		if (bolo)		
			fill_csv(tmp_buf, map);
		else
		{
			if (fill_arg(tmp_buf, bit))
			{
				bit->print(bit->get_list(), bit->get_nbr());
			}
		}
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: Argument.\n";
		return 1;
	}
	try
	{
		BitcoinExchange(argv[1], "data.csv");
	}
	catch (std::exception &e)
	{
	}
}
