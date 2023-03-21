#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class	Zombie
{
	public:
	Zombie(void);
	~Zombie(void);
	
	void	announce(void);
	void	set_name(std::string const & zname);

	private:
	std::string	_name;

};

#endif