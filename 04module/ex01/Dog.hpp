#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:

	Brain*	_brn;

	public:
	Dog();
	Dog(const Dog &copy);
	Dog &operator=(Dog const &copy);
	~Dog();

	void makeSound() const;
};

#endif