#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	public:
	void	annouce(void);
	Zombie();
	Zombie(std::string name);
	~Zombie();

	private:
	std::string	_name;
};

void	randomChump( std::string name );
Zombie*	newZombie( std::string name );

#endif
