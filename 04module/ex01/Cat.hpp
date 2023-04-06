#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:

	Brain*	_brn;

	public:
	Cat();
	Cat(const Cat &copy);
	Cat &operator=(Cat const &copy);
	~Cat();

	void makeSound() const;
};

#endif