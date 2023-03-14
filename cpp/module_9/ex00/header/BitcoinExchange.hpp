#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <list>
#include <iomanip>

typedef std::multimap<std::list<int>, double> multimap;

class BitcoinExchange
{

	/*******************/
	/*      CANON      */
	/*******************/

	public:
	BitcoinExchange(std::string, std::string);
	BitcoinExchange(BitcoinExchange const &src);
	~BitcoinExchange();
	BitcoinExchange	&operator=(BitcoinExchange const &src);
	void			print_ratio(void);
	void			print(std::list<int>, double);
	void			print_str(int year, int month, int day, double nbr, double second);
	std::list<int>	get_list(void);
	double			get_nbr(void);
	void			set_list(std::list<int>);
	void			set_nbr(double);

	private:
	BitcoinExchange();
	multimap		_arg;
	multimap		_map;
	std::list<int>	_list;
	double			_nbr;
};

void	 fill_into_map(std::string str, bool bolo, multimap &map, BitcoinExchange *);

#endif
