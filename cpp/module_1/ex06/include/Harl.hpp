#ifndef HARL_HPP
#define HARL_HPP

#include "main.hpp"

enum cmd {
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	DEFAULT
};

class Harl
{
	public:
	Harl();
	void	complain(std::string level);

	private:	
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
};

#endif
