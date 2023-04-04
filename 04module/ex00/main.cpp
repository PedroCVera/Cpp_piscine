#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

// int main()
// {
// 	const Animal* meta = new Animal();
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();
	
// 	std::cout << j->getType() << " " << std::endl;
// 	std::cout << i->getType() << " " << std::endl;
// 	i->makeSound(); //will output the cat sound!
// 	j->makeSound();
// 	meta->makeSound();

// 	return 0;
// }

int main()
{
	const Animal *meta = new Animal();
	meta->makeSound();
	std::cout << meta->getType() << " " << std::endl;
	delete meta;
	std::cout << std::endl;

	const Animal *i = new Cat();
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	delete i;
	std::cout << std::endl;

	const Animal *j = new Dog();
	std::cout << j->getType() << " " << std::endl;
	j->makeSound();
	delete j;
	std::cout << std::endl;

	const WrongAnimal *w = new WrongAnimal();
	w->makeSound();
	std::cout << w->getType() << " " << std::endl;
	delete w;
	std::cout << std::endl;

	const WrongCat *wc = new WrongCat();
	wc->makeSound();
	std::cout << wc->getType() << " " << std::endl;
	delete wc;

	return 0;
}
