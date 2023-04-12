#include "../inc/Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Hole music starts." << std::endl;
	return ;
}

Cure::Cure(Cure const &copy) : AMateria(copy)
{
}

Cure &Cure::operator=(Cure const &other)
{
	if (this != &other)
	{
		AMateria::operator=(other);
	}
	return *this;
}

Cure::~Cure()
{
}

//	METHODS

AMateria *Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}