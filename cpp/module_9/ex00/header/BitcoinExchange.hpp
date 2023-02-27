#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>

class BitcoinExchange
{

	/*******************/
	/*      CANON      */
	/*******************/

	public:
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange const &src);
	~BitcoinExchange();
	BitcoinExchange	&operator=(BitcoinExchange const &src);

	private:

};

#endif