#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	private:
	int					_fixed;
	static const int	_bits;

	public:

	Fixed();
	Fixed(const Fixed &copy);
	Fixed &operator=(const Fixed &copy);
	int		getRawBits() const;
	void 	setRawBits(int const raw);
	~Fixed();
};

#endif