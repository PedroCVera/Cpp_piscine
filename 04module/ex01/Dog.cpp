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

Dog &Dog::operator=(Dog const &other)
{
	std::cout << "Dog assignation operator called" << std::endl;
	if (this != &other)
	{
		_type = other._type;
		if (!_brn)
			delete _brn;
		this->_brn = new Brain(*other._brn);
	}
	return *this;
}

Dog::~Dog()
{
	delete _brn;
	std::cout << "Destructor has been called. Dog." << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "AU AU AU AU AU AU AU AU" << std::endl;
}