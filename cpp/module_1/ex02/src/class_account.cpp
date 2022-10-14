#include "../Account.hpp"
# include <ctime>
# include <iomanip>
# include <iostream>

int	Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int	Account::_nbAccounts = 0;

Account::Account(int inital_deposit)
{
	this->_amount = inital_deposit;
	this->_accountIndex = Account::getNbAccounts();
	this->_displayTimestamp();
	std::cout << "index:"<< this->_accountIndex << ";amount:";
	std::cout << this->_amount << ";created" << std::endl;
	Account::_nbAccounts ++;
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
	std::tm	*tm;

	std::time (&timetoday);
	tm = std::localtime(&timetoday);
	std::cout << "[" << tm->tm_year + 1900 << tm->tm_mon << tm->tm_mday << "_" << tm->tm_hour << tm->tm_min << tm->tm_sec << "] ";
}
