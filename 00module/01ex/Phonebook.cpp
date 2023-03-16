#include "main.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "Bob the builder was called for the cables" << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "cut hem cables" << std::endl;
}

void	PhoneBook::printH(void)
{
	std::cout << "";
	std::cout << " " << std::string(43, '_') << std::endl;
	std::cout << "|          |          |          |          |" << std::endl;
	std::cout << "|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|" << std::endl;
	std::cout << "|__________|__________|__________|__________|" << std::endl;
	std::cout << "";
}

int    PhoneBook::indexsearch(void)
{
	std::string    index;

	std::getline(std::cin, index);
	if (!std::cin)
		return (1);
	for (int i = 0; index[i]; i++)
	{
		if (index.length() == 0 || index[i] <= '0' || index[i] >= '9')
		{
			std::cout << "Not a valid index" << std::endl;
			return 0;
		}
	}
	if (index.length() != 1 || index[0] == '9' || !cont[index[0] - 49].status())
	{
		std::cout << "Index out of range" << std::endl;
		return 0;
	}
	std::cout << "First name    : " << cont[index[0] - 49].get_param(1) << std::endl;
	std::cout << "Last name     : " << cont[index[0] - 49].get_param(2) << std::endl;
	std::cout << "Nickname      : " << cont[index[0] - 49].get_param(3) << std::endl;
	std::cout << "Phone number  : " << cont[index[0] - 49].get_param(4) << std::endl;
	std::cout << "Darkest secret: " << cont[index[0] - 49].get_param(5) << std::endl;
	std::getline(std::cin, index);
	return (1);
}

void	PhoneBook::pparam(int i, int i2)
{
	std::string	str;

	if (cont[i].get_param(i2).length() < 9)
	{
		std::cout << std::setw(10);
		std::cout << cont[i].get_param(i2);
		return ;
	}
	for (int ind = 0; ind < 9; ind++)
		std::cout << cont[i].get_param(i2)[ind];
	if (cont[i].get_param(i2).length() == 10)
		std::cout << cont[i].get_param(i2)[9];
	else
		std::cout << ".";
}

void	PhoneBook::Search(void)
{
	if (cont[0].status() == 0)
	{
		std::cout << "It's so empty here... maybe you should try adding some contacts" << std::endl;
		return ; 
	}
	printH();
	for (int i = 0; i < 8; i++)
	{
        if (cont[i].status())
        {
            std::cout << "";
            std::cout << "|          |          |          |          |" << std::endl;
            std::cout << "|     " << i + 1 << "    ";
            for (int i2 = 1; i2 < 4; i2++)
            {
                std::cout << "";
                std::cout << "|";
                std::cout << "";
                pparam(i, i2);
            }
            std::cout << "";
            std::cout << "|" << std::endl;
            std::cout << "|__________|__________|__________|__________|";
            std::cout << "" << std::endl;
        }
	}
	std::cout << "\n\n\n";
	std::cout << "Which index would you like to display?" << std::endl;
	while (!indexsearch())
		;
}