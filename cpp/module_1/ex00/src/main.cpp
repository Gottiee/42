#include "../Zombie.hpp"

int main(void)
{
	Zombie	*newZomb = newZombie("heap zombie");
	randomChump("stack zombie");
	delete newZomb;
}
