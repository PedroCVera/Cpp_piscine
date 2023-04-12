#include "../inc/AMateria.hpp"

AMateria::AMateria(std::string const &type)
{
	_type = type;
	return ;
}

AMateria::AMateria(AMateria const& copy)
{
	*this = copy;
}

AMateria &AMateria::operator=(AMateria const &other)
{
	if (this != &other)
	{
		_type = other._type;
	}
	return *this;
}

AMateria::~AMateria()
{
}

std::string const &AMateria::getType() const
{
	return _type;
}