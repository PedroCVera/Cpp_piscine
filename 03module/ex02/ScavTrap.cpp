#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	_hp = 100;
	_ep = 50;
	_ad = 20;
	std::cout << "ScavTrap default constructor." << std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string const & name)
{
	_name = name;
	_hp = 100;
	_ep = 50;
	_ad = 20;
	std::cout << "ScavTrap constructor." << std::endl;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const & copy) : ClapTrap(copy)
{
	std::cout << "ScavTrap copy constructor." << std::endl;
	*this = copy;
	return ;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hp = other._hp;
		this->_ep = other._ep;
		this->_ad = other._ad;
	}
	std::cout << "ScavTrap = assignation operator." << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << _name << " ScavTrap Constructor." << std::endl;
	return ;
}

void	ScavTrap::attack(std::string const & target)
{
	if (_hp > 0 && _ep > 0)
	{
		_ep -= 1;
		std::cout << "ScavTrap:" << _name << " has attacked " << target \
		<< " dealing " << _ad << " points damage!" << std::endl;
	}
	else
		std::cout << "Not enough hit/energy points!" << std::endl;
	return ;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " has entered gate keeper mode." \
	<< std::endl;
}




