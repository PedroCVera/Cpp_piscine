#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
	public:
	Cat();
	Cat(const Cat &copy);
	Cat &operator=(Cat const &copy);
	~Cat();

	void makeSound() const;
};

#endif