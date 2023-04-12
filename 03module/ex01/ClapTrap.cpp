#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->_name = "default";
	this->_hp = 10;
	this->_ep = 10;
	this->_ad = 0;
	return ;
}

ClapTrap::ClapTrap(std::string const &name)
{
	_name = name;
	_hp = 10;
	_ep = 10;
	_ad = 0;
	std::cout << _name << " has been spawned." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
	*this = copy;
	std::cout << _name << " has been copied" << std::endl;
	return ;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &other)
{
	_name = other._name;
	_hp = other._hp;
	_ep = other._ep;
	_ad = other._ad;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << _name << " has been destroyed" << std::endl;
	return ;
}

void	ClapTrap::attack(const std::string& target)
{
	if (_hp > 0 && _ep > 0)
	{
		_ep -= 1;
		std::cout << _name << " has attacked " << target << \
		" and caused " << _ad << " points of damage." << std::endl;
	}
	else
		std::cout << "Not enough hit points/energy points \
		to perform this action." << std::endl;
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hp > 0)
	{
		_hp -= amount;
		std::cout << _name << " has taken " << amount << " damage." << std::endl;
	}
	else
		std::cout << _name << " is already dead." << std::endl;
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_ep > 0)
	{
		_ep -= 1;
		_hp += amount;
		std::cout << _name << " has been healed for:" << amount << \
		" amount of points and now has:" << _hp << std::endl;
	}
	else
		std::cout << _name << " has not enough energy to perform this action." \
		<< std::endl;
	return ;
}