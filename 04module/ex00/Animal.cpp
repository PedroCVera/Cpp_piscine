#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Default constructor for Animal. Animal." << std::endl;
	return ;
}

Animal::Animal(const Animal &copy)
{
	*this = copy;
	std::cout << type << " has called copy constructor. Animal." << std::endl;
	return ;
}

Animal &Animal::operator=(Animal const &copy)
{
	type = copy.type;
	std::cout << "Copy operator as been called. Animal." << std::endl;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Destructor has been called. Animal." << std::endl;
}

void	Animal::makeSound() const
{
	std::cout << "Meeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee" << std::endl;
}

std::string	Animal::getType() const
{
	return (type);
}