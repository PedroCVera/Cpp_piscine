#include "Zombie.hpp"

Zombie* newZombie(std::string const & name);

void	randomChump(std::string const & name);

int	main(void)
{
	Zombie *BrainEater;

	BrainEater = newZombie("Bob");
	BrainEater->announce();
	std::cout << "\n\n\n" << std::endl;
	randomChump("ze");
	std::cout << "\n\n\n" << std::endl;
	delete BrainEater;
}