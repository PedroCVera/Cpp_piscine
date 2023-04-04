#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "Default constructor for WrongCat. WrongCat." << std::endl;
	return ;
}

WrongCat::WrongCat(const WrongCat &copy)
{
	*this = copy;
	std::cout << type << " has called copy constructor. WrongCat." << std::endl;
	return ;
}

WrongCat &WrongCat::operator=(WrongCat const &copy)
{
	type = copy.type;
	std::cout << "Copy operator as been called. WrongCat." << std::endl;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "Destructor has been called. WrongCat." << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "am i a dog? be or not to be a dog?" << std::endl;
}