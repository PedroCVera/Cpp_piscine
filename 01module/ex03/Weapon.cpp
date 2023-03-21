#include "Weapon.hpp"

Weapon::Weapon(void)
{
	std::cout << "Constructor has been called for Weapon!" << std::endl;
	return ;
}

Weapon::~Weapon(void)
{
	std::cout << "Destructor has been called for Weapon!" << std::endl;
}

std::string const & Weapon::getType(void)
{
	std::string &ref = this->_type;
	return (ref);
}

void	Weapon::setType(std::string str)
{
	this->_type = str;
	return ;
}