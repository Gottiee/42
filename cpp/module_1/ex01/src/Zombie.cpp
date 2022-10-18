#include "../Zombie.hpp"

int Zombie::_nbr_zombie = 0;

Zombie::Zombie(void)
{
	Zombie::_nbr_zombie ++;
}

int	Zombie::get_nbr_zombie(void)
{
	return(Zombie::_nbr_zombie);
}

void	Zombie::set_name(std::string nameu)
{
	this->_name = nameu;
}

/*Zombie::Zombie(std::string name): _name(name)
{
	annouce();	
}*/

void	Zombie::annouce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->_name << " trepassed..." << std::endl;
	Zombie::_nbr_zombie --;
}
