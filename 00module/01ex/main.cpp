#include "main.hpp"

int	main(void)
{
	int			ind = 0;
	PhoneBook	P;
	std::string	input;

	while (1)
	{
		std::system("CLS");
		std::cout << "Please choose one command:\nAdd; Search; Exit" << std::endl;
		std::getline(std::cin, input);
		if (!std::cin)
			return (0);
		if (input == "Add")
		{
			std::system("CLS");
			std::cout << "This contact will be saved in the index number:" << (ind % 8) + 1 << std::endl;
			P.cont[ind % 8].set_contact();
			ind++;
		}
		else if(input == "Exit")
		{
			return (0);
		}
		else if(input == "Search")
		{
			std::system("CLS");
			P.Search();
		}
		else
		{
			std::cout << "The option you chose is not an option, please choose one of the available ones" << std::endl;
		}
		std::system("CLS");
	}
}