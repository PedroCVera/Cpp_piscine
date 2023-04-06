#include "Dog.hpp"

Dog::Dog()
{
	_brn = new Brain();
	_type = "dog";
	std::cout << "Default constructor for Dog. Dog." << std::endl;
	return ;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	*this = copy;
	std::cout << _type << " has called copy constructor. Dog." << std::endl;
	return ;
}

Dog &Dog::operator=(Dog const &copy)
{
	_type = copy._type;
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