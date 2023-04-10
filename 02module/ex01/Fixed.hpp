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

	Fixed &operator=(const Fixed &copy);
	
	int		getRawBits () const;
	void 	setRawBits (int const raw);
	float	toFloat (void) const;
	int		toInt (void) const;
	~Fixed ();
};

std::ostream &operator<<(std::ostream &out, const Fixed &f);

#endif