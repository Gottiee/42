#include "../Account.hpp"
# include <ctime>
# include <iomanip>
# include <iostream>

/*getter*/
int	Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int Account::getNbDeposits(void)
{
	return(_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

/*setter*/
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/*constructer*/
Account::Account(int inital_deposit): _nbDeposits(0), _nbWithdrawals(0)
{
	this->_amount = inital_deposit;
	this->_accountIndex = Account::getNbAccounts();
	this->_displayTimestamp();
	std::cout << "index:"<< this->_accountIndex << ";amount:";
	std::cout << this->_amount << ";created" << std::endl;
	Account::_nbAccounts ++;
	Account::_totalAmount += inital_deposit;
}

/*destructer*/
Account::~Account()
{
	Account::_displayTimestamp();
	std::cout << "index:"<< this->_accountIndex << ";amount:";
	std::cout << this->_amount << ";closed" << std::endl;
}


void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";total:";
	std::cout << Account::getTotalAmount() << ";deposits:" << Account::getNbDeposits();
	std::cout << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void	Account::_displayTimestamp(void)
{
	//std::cout << "[19920104_091532] ";
	time_t	timetoday;
	std::tm	*tm;

	std::time (&timetoday);
	tm = std::localtime(&timetoday);
	std::cout << "[" << tm->tm_year + 1900 << tm->tm_mon << tm->tm_mday << "_" << tm->tm_hour << tm->tm_min << tm->tm_sec << "] ";
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:"<< this->_accountIndex << ";amount:";
	std::cout << this->_amount << ";deposits:" << this->_nbDeposits;
	std::cout << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	std::cout << "index:"<< this->_accountIndex << ";p_amount:";
	std::cout << this->_amount << ";deposit:" << deposit << ";amount:";
	Account::_totalNbDeposits ++;
	Account::_totalAmount += deposit;
	this->_amount += deposit;
	this->_nbDeposits ++;
	std::cout << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << "index:"<< this->_accountIndex << ";p_amount:";
	std::cout << this->_amount << ";withdrawal:";
	if (this->_amount - withdrawal < 0)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	Account::_totalNbWithdrawals ++;
	Account::_totalAmount -= withdrawal;
	this->_amount -= withdrawal;
	this->_nbWithdrawals ++;
	std::cout << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:";
	std::cout << this->_nbWithdrawals << std::endl;
	return (true);
}
