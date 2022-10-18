#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	public:
	Zombie();
	~Zombie();
	void	annouce(void);
	void	set_name(std::string nameu);
	int		get_nbr_zombie(void);

	private:
	std::string	_name;
	static int	_nbr_zombie;
};

Zombie	*zombieHorde(int N, std::string name);

#endif
