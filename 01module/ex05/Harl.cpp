#include "Harl.hpp"

Harl::Harl()
{
	std::cout << "MA BOY HARL IS HERE!" << std::endl;
	return ;
}

Harl::~Harl()
{
	std::cout << "Awww, harl is gone..." << std::endl;
	return ;
}

void	Harl::debug(void)
{
	std::cout << "love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "his is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	if (level != "Debug" && level != "Info" && level != "Warning" && level != "Error")
	{
		std::cout << "Parameter is not an Option, please choose a valid option and try again." << std::endl;
		return ;
	}
	void (Harl::*func[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string options[4] = {"Debug", "Info", "Warning", "Error"};
	for (int i = 0; i < 4; i++)
	{
		if (level == options[i])
			(this->*func[i])();
	}
	return ;
}