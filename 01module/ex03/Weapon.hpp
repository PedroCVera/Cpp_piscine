#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class	Weapon
{
	private:
	std::string	_type;

	public:
	Weapon(void);
	explicit Weapon(std::string type);
	~Weapon(void);

	std::string	const &getType();
	void	setType(std::string	str);
};

#endif