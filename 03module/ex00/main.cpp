#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap clapTrap1("AmazingClapThatTraps");

    clapTrap1.attack("Some random dude");
    clapTrap1.takeDamage(10);
    clapTrap1.takeDamage(10);
    for (int i = 0; i < 10; i++)
	{
		clapTrap1.beRepaired(i);
		std::cout << i << std::endl;
	}
	clapTrap1.takeDamage(10);
}