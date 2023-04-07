#include "Cat.hpp"

Cat::Cat()
{
	_brn = new Brain();
	_type = "cat";
	std::cout << "Default constructor for Cat. Cat." << std::endl;
	return ;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	*this = copy;
	std::cout << _type << " has called copy constructor. Cat." << std::endl;
	return ;
}

Cat &Cat::operator=(Cat const &copy)
{
	_type = copy._type;
	std::cout << "Copy operator as been called. Cat." << std::endl;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Destructor has been called. Cat." << std::endl;
}

void	Cat::makeSound() const
{
	delete _brn;
	std::cout << "B*tch, stop looking at me!" << std::endl;
}