#include "../include/Harl.hpp"

Harl::Harl(void)
{
		
}

void	Harl::debug(void)
{
	std::cout << "I like Potato" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "i want Potato" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "You puted to much oil in the Potato..." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "YOU BURN THE POTATO !!!" << std::endl;
}

cmd resolveOption(std::string level)
{
    if (level == "INFO")
		return INFO;
    if (level == "DEBUG")
		return DEBUG;
	if (level == "WARNING")
		return WARNING;
	if (level == "ERROR")
		return ERROR;
    return DEFAULT;
 }

void	Harl::complain(std::string level)
{
	

	cmd resolveOption(std::string level);
	switch (resolveOption(level))
	{
		case DEBUG:
			this->debug();
			break;
		case INFO:
			this->info();
			break;
		case ERROR:
			this->error();
			break;
		case WARNING:
			this->warning();
			break;
		case DEFAULT:
			std::cout << "NANI ?" << std::endl;
	}
}
