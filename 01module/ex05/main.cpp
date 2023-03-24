#include "Harl.hpp"

int	main(void)
{
	Harl	harl;
	
	std::cout << "Debug:" << std::endl;
	harl.complain("DEBUG");
	std::cout << "Info:" << std::endl;
	harl.complain("Info");
	std::cout << "Warning" << std::endl;
	harl.complain("Warning");
	std::cout << "Error" << std::endl;
	harl.complain("Error");
	std::cout << "errado" << std::endl;
	harl.complain("errado");

	return (0);
}