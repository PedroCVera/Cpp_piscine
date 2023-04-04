#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "Default constructor for WrongAnimal. WrongAnimal." << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	*this = copy;
	std::cout << type << " has called copy constructor. WrongAnimal." << std::endl;
	return ;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &copy)
{
	type = copy.type;
	std::cout << "Copy operator as been called. WrongAnimal." << std::endl;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor has been called. WrongAnimal." << std::endl;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "WRONG SOUNDS" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return (type);
}