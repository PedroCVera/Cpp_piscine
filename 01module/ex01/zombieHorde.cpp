#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string const name)
{
	Zombie *brainchomp;
	int		i = -1;

	brainchomp = new Zombie[N];
	while (i++ < N -1)
	{
		brainchomp[i].set_name(name);	}
	return (brainchomp);
}