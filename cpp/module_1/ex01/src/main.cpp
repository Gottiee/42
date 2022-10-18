#include "../Zombie.hpp"

int main(void)
{
	Zombie *heap = zombieHorde(10, "petit Zombie");
	std::cout << heap->get_nbr_zombie() << " zombie cree" << std::endl;
	delete [] heap;
	std::cout << heap->get_nbr_zombie() << " zombie restant" << std::endl;
}
