#include "../inc/Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "The air freezes." << std::endl;
}

Ice::Ice(Ice const &copy) : AMateria(copy)
{
}

Ice &Ice::operator=(Ice const &other)
{
	if (this != &other)
	{
		AMateria::operator=(other);
	}
	return *this;
}

Ice::~Ice()
{
}

//	METHODS

AMateria *Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}