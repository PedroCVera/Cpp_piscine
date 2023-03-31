#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class	ClapTrap
{

	protected:

	std::string		_name;
	unsigned int	_hp;
	unsigned int	_ep;
	unsigned int	_ad;

	public:

	ClapTrap();
	ClapTrap(std::string const &name);
	ClapTrap(const ClapTrap& copy);
	~ClapTrap();

	ClapTrap& operator=(ClapTrap const &other);

	virtual void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

};


#endif