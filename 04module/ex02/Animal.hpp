#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal	
{
	protected:

	std::string _type;

	public:
	Animal();
	Animal(const Animal &copy);
	Animal &operator=(Animal const &copy);
	virtual ~Animal();

	virtual void makeSound() const = 0;
	std::string	getType() const;
};

#endif