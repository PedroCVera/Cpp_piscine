#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Default constructor for Dog. Dog." << std::endl;
	return ;
}

Dog::Dog(const Dog &copy)
{
	*this = copy;
	std::cout << type << " has called copy constructor. Dog." << std::endl;
	return ;
}

Dog &Dog::operator=(Dog const &copy)
{
	type = copy.type;
	std::cout << "Copy operator as been called. Dog." << std::endl;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Destructor has been called. Dog." << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "AU AU AU AU AU AU AU AU" << std::endl;
}