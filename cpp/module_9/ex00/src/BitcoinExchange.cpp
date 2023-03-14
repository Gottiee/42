#include "../header/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string arg,  std::string map)
{
	fill_into_map(map, true, _map, this);
	try
	{
		fill_into_map(arg, false, _arg, this);
	}
	catch (std::exception &e)
	{
		throw;
	}
}

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
	*this = src;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &src)
{
	_arg = src._arg;
	_map = src._map;
	return *this;
}

void	BitcoinExchange::print_ratio(void)
{
	for (multimap::iterator arg_it = _arg.begin(); arg_it != _arg.end(); arg_it ++)
	{
		print((*arg_it).first, (*arg_it).second);
	}
}

void	BitcoinExchange::print(std::list<int> list, double nbr)
{
	std::list<int>::iterator	month = list.begin();
	std::list<int>				tmp;
	std::list<int>::iterator	month_map;

	month ++;
	for (multimap::reverse_iterator map_it = _map.rbegin(); map_it != _map.rend(); map_it ++)
	{
		if ((*map_it).first.front() < list.front())
		{
			print_str(list.front(), (*month), list.back(), nbr, (*map_it).second);
			return ;
		}
		if ((*map_it).first.front() == list.front())
		{
			tmp = (*map_it).first;
			month_map = tmp.begin();
			month_map ++;
			if ((*month_map) < (*month))
			{
				print_str(list.front(), (*month), list.back(), nbr, (*map_it).second);
				return ;
			}
			if ((*month_map) == (*month))
			{
				if ((*map_it).first.back() <= list.back())
				{
					print_str(list.front(), (*month), list.back(), nbr, (*map_it).second);
					return ;
				}
			}
		}
	}
}

void	BitcoinExchange::print_str(int year, int month, int day, double nbr, double second)
{
	std::cout.fill('0');
	std::cout << year << "-" << std::setw(2) << std::right <<  month << "-" << std::setw(2) << std::right << day;
	std::cout << " => " << nbr << " = " << nbr * second << std::endl;
}

std::list<int>	BitcoinExchange::get_list()
{
	return _list;
}

double	BitcoinExchange::get_nbr(void)
{
	return _nbr;
}

void	BitcoinExchange::set_list(std::list<int> list)
{
	_list = list;
}

void	BitcoinExchange::set_nbr(double nbr)
{
	_nbr = nbr;	
}
