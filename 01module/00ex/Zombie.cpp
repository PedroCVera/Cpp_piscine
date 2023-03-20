#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "A Zombie has wandered in..." << std::endl;
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << "Zombie " << this->_name << " has been destroyed!" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}

void	Zombie::set_name(std::string const & name)
{
	this->_name = name;
	return ;
}