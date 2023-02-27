#include "../header/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::cout << "Default constructor call for BitcoinExchange" << std::endl;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
	*this = src;
	std::cout << "Copy constructor call for BitcoinExchange" << std::endl;
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "Default destuctor call for BitcoinExchange" << std::endl;
}

BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &src)
{
	std::cout << "Default assignement constructor call for BitcoinExchange" << std::endl;
	return *this;

}