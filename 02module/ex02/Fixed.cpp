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

// ------------ OPERATORS ------------

Fixed &Fixed::operator=(const Fixed &copy)
{
//	std::cout << "Copy assignment operator called" << std::endl; silenced for ex02
	this->_fixed = copy.getRawBits();
	return *this;
}

bool	Fixed::operator==(const Fixed &copy) const
{
	return this->_fixed == copy.getRawBits();
}

bool	Fixed::operator!=(const Fixed &copy) const
{
	return (this->_fixed != copy.getRawBits());
}

bool	Fixed::operator>(const Fixed &copy) const
{
	return (this->_fixed > copy.getRawBits());
}

bool	Fixed::operator<(const Fixed &copy) const
{
	return (this->_fixed < copy.getRawBits());
}

bool	Fixed::operator>=(const Fixed &copy) const
{
	return (this->_fixed >= copy.getRawBits());
}

bool	Fixed::operator<=(const Fixed &copy) const
{
	return (this->_fixed <= copy.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &copy) const
{
	Fixed result;
	result.setRawBits(this->_fixed + copy.getRawBits());
	return (result);
}

Fixed	Fixed::operator-(const Fixed &copy) const
{
	Fixed result;
	result.setRawBits(this->_fixed - copy.getRawBits());
	return (result);
}

Fixed	Fixed::operator*(const Fixed &copy) const
{
	Fixed result;
	result.setRawBits(this->_fixed * copy.getRawBits() / (1 << this->_bits));
	return (result);
}

Fixed	Fixed::operator/(const Fixed &copy) const
{
	Fixed result;
	result.setRawBits(this->_fixed / copy.getRawBits() * (1 << this->_bits));
	return (result);
}

Fixed&	Fixed::operator++()
{
	this->_fixed += (1 << this->_bits);
	return (*this);
}

Fixed&	Fixed::operator--()
{
	this->_fixed -= (1 << this->_bits);
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed result(*this);
	++(*this);
	return (result);
}

Fixed Fixed::operator--(int)
{
	Fixed result(*this);
	--(*this);
	return (result);
}



// ------------ OPERATORS ------------

// ------------ min/max ------------

Fixed& Fixed::min(Fixed &o1, Fixed &o2)
{
	return (o1 < o2 ? o1 : o2);
}

Fixed& Fixed::max(Fixed &o1, Fixed &o2)
{
	return (o1 > o2 ? o1 : o2);
}

const Fixed& Fixed::min(const Fixed &o1, const Fixed &o2)
{
	return (o1 < o2 ? o1 : o2);
}

const Fixed& Fixed::max(const Fixed &o1, const Fixed &o2)
{
	return (o1 > o2 ? o1 : o2);
}

// ------------ min/max ------------


int	Fixed::getRawBits() const
{
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
