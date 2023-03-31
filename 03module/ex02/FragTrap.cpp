#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	_hp = 100;
	_ep = 100;
	_ad = 30;
	std::cout << "FragTrap default constructor." << std::endl;
}

FragTrap::FragTrap(std::string const& name)
{
	_name = name;
	_hp = 100;
	_ep = 100;
	_ad = 30;
	std::cout << "FragTrap constructor." << std::endl;
}

FragTrap::FragTrap(FragTrap const& copy) : ClapTrap(copy)
{
	*this = copy;
	std::cout << "FragTrap copy constructor." << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &other)
{
	_hp = other._hp;
	_ep = other._ep;
	_ad = other._ad;
	_name = other._name;
	std::cout << "FragTrap assignment = operator." << std::endl;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << _name << " FragTrap has been destroyed." << std::endl;
}

void	FragTrap::highFivesGuys()
{
	std::cout << _name << " gives highfives!" << std::endl;
}