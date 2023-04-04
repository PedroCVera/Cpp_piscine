#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Default constructor for Cat. Cat." << std::endl;
	return ;
}

Cat::Cat(const Cat &copy)
{
	*this = copy;
	std::cout << type << " has called copy constructor. Cat." << std::endl;
	return ;
}

Cat &Cat::operator=(Cat const &copy)
{
	type = copy.type;
	std::cout << "Copy operator as been called. Cat." << std::endl;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Destructor has been called. Cat." << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "B*tch, stop looking at me!" << std::endl;
}