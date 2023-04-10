#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string const name);

int	main(void)
{
	int		n = 42;
	int		i = -1;
	Zombie *Braineater;

	Braineater = zombieHorde(n, "Bob");
	while (i++ < n - 1)
		Braineater[i].announce();
	delete [] Braineater;
}