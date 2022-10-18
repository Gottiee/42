#include "../Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie *zomb = new Zombie[N];
	for (int i = 0; i < N; i ++)
	{
		zomb[i].set_name(name);
		zomb[i].annouce();
	}
	return (&zomb[0]);
}
