#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class	Weapon
{
	private:
	std::string	_type;

	public:
	Weapon(void);
	~Weapon(void);

	std::string	const &getType();
	void	setType(std::string	str);
};

#endif