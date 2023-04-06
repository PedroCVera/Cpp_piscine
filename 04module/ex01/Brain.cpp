#include "Brain.hpp"

Brain::Brain()
{
	_ideas = new std::string[100];
	for (int i = 0;i < 100; i++)
		_ideas[i] = (std::string)"A" + (std::string)"a";
	std::cout << "Brain default constructor." << std::endl;
}

Brain::Brain(Brain const &copy)
{
	_ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		_ideas[i] = copy._ideas[i];
	std::cout << "Brain copy constructor." << std::endl;
}

Brain &Brain::operator=(Brain const &other)
{
	if (this != &other)
	{
		delete[] _ideas;
		_ideas = new std::string[100];
		for (int i = 0; i < 100; i++)
			_ideas[i] = other._ideas[i];
	}
	std::cout << "Brain operator constructor." << std::endl;
	return (*this);
}

Brain::~Brain()
{
	delete[] _ideas;
	std::cout << "Brain destructor." << std::endl;
}