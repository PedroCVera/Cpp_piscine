#include "HumanB.hpp"

HumanB::HumanB(std::string name, Weapon &weapon) : _weapon(weapon)
{
	this->_name = name;
	this->_weapon = weapon;
	return ;
}

HumanB::~HumanB(void)
{
	std::cout << "Destroy HumanB." << std::endl;
	return ;
}

void HumanB::attack()
{
    std::cout << this->_name << " attacks with his " << this->_weapon.getType() << std::endl;
}