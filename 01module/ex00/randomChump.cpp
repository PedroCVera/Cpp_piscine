#include "Zombie.hpp"

void	randomChump(std::string const & name)
{
	Zombie z;

	z.set_name(name);
	z.announce();
}