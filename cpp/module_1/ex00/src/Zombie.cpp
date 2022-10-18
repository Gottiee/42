#include "../Zombie.hpp"

Zombie::Zombie(void)
{

}

Zombie::Zombie(std::string name): _name(name)
{
	annouce();	
}

void	Zombie::annouce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->_name << " trepassed..." << std::endl;
}
