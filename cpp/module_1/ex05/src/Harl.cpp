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

void	Harl::complain(std::string level)
{
	void	(Harl::*ptr[])(void) = {
	&Harl::debug,
	&Harl::info,
	&Harl::warning,
	&Harl::error
	};

	std::string	tab[] = {
	"DEBUG",
	"INFO",
	"WARNING", 
	"ERROR"
	};

	int i = -1;
	while (++i < 4)
	{
		if (level == tab[i])
			(this->*(ptr[i]))();
	}
}
