#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <iomanip>
#include <cmath>

class Fixed
{
	private:
	int					_fixed;
	static const int	_bits = 8;

	public:

	Fixed ();
	Fixed (const Fixed &copy);
	Fixed (const int numb);
	Fixed (const float flot);

	bool	operator==(const Fixed &copy) const;
	bool	operator!=(const Fixed &copy) const;
	bool	operator>(const Fixed &copy) const;
	bool	operator<(const Fixed &copy) const;
	bool	operator>=(const Fixed &copy) const;
	bool	operator<=(const Fixed &copy) const;

	Fixed	&operator=(const Fixed &copy);
	Fixed	operator+(const Fixed &copy) const;
	Fixed	operator-(const Fixed &copy) const;
	Fixed	operator*(const Fixed &copy) const;
	Fixed	operator/(const Fixed &copy) const;

	Fixed&	operator++();
	Fixed&	operator--();
	Fixed	operator++(int);
	Fixed	operator--(int);

	static Fixed	&min(Fixed &o1, Fixed &o2);
	static const Fixed	&min(const Fixed &o1, const Fixed &o2);
	static Fixed	&max(Fixed &o1, Fixed &o2);
	static const Fixed	&max(const Fixed &o1, const Fixed &o2);

	int		getRawBits () const;
	void 	setRawBits (int const raw);
	float	toFloat (void) const;
	int		toInt (void) const;
	~Fixed ();
};

std::ostream &operator<<(std::ostream &out, const Fixed &f);

#endif