#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
//    Animal test;

    Animal *a = new Dog();
    a->makeSound();
    delete a;
    std::cout << std::endl;

    Animal *b = new Cat();
    b->makeSound();
    delete b;
    std::cout << std::endl;

    return 0;
}
