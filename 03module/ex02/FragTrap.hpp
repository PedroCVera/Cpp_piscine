#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class	FragTrap : public ClapTrap
{
	public:

	FragTrap();
	FragTrap(std::string const & name);
	FragTrap(FragTrap const &copy);
	~FragTrap();

	FragTrap &operator=(FragTrap const & other);

	void	highFivesGuys(void);
	
};

#endif