#include "Fixed.hpp"

Fixed::Fixed() : _fixed(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
	return ;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixed = copy.getRawBits();
	return *this;
}

Fixed::Fixed (const int numb)
{
	std::cout << "Integer constructor called" << std::endl;
	this->_fixed = numb << this->_bits;
	return ;
}

Fixed::Fixed (const float flot)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixed = roundf(flot * (1 << this->_bits));
	return ;
}

int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixed;
}

void Fixed::setRawBits(int const raw)
{
	this->_fixed = raw;
	return ;
}

float Fixed::toFloat() const
{
	return roundf(this->_fixed) / (1 << this->_bits);
}

int Fixed::toInt() const
{
	return this->_fixed >> this->_bits;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

std::ostream &operator<<(std::ostream &out, const Fixed &f)
{
	out << f.toFloat();
	return (out);
}
