#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int	main(int ac, char *av[])
{
	if (ac == 4)
	{
		std::ifstream in_file(av[1]);
		if (!in_file.is_open())
		{
			std::cout << "Error: There is no file or wrong permissions" << std::endl;
			return 1;
		}
		if (in_file.peek() == std::ifstream::traits_type::eof())
		{
			std::cout << "Error: file is empty" << std::endl;
			return 1;
		}
		std::string haysack;
		std::ofstream file(((std::string)av[1] + ".replace").c_str());
		if (!file)
		{
			std::cout << "Error creating the file" << std::endl;
			return 1;
		}
		while (std::getline(in_file, haysack))
		{
			while (std::string::npos != haysack.find(av[2]))
			{
				haysack.insert(haysack.find(av[2]), av[3]);
				haysack.erase(haysack.find(av[2]), ((std::string)av[2]).length());
			}
			file << haysack << std::endl;
		}
	}
	else
	{
		std::cout << "Input is incorrect, use: '/replace <filename> <str1> <str2>' !" << std::endl;
	}
	return 0;
}