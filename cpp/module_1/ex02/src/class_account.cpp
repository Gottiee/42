#include "../Account.hpp"
# include <ctime>
# include <iomanip>
# include <iostream>

Account::Account(int inital_deposit)
{
	//print la creation du comptes etc..
	this->_displayTimestamp();
}

Account::~Account()
{
	//print la destruction du compte
}

void	Account::displayAccountsInfos(void)
{
		
}

void	Account::_displayTimestamp(void)
{
	time_t	timetoday;
	std::tm	tm;

	std::time (&timetoday);
	std::cout << std::asctime(localtime((&timetoday)));
}
