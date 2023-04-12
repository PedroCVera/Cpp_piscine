#include "../inc/Character.hpp"

Character::Character(std::string const &name) : _name(name)
{
	std::cout << "Character " << name << " created!" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		_inv[i] = NULL;
	}
}

Character::Character(Character const &copy) : _name(copy._name)
{
	std::cout << "Character " << _name << " copied." << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (copy._inv[i])
			_inv[i] = copy._inv[i]->clone();
		else
			_inv[i] = NULL;
	}
}

Character &Character::operator=(Character const &other)
{
	if (this != &other)
	{
		_name = other._name;
		for (int i = 0; i < 4; i++)
		{
			if (_inv[i])
				delete _inv[i];
			if (other._inv[i])
				_inv[i] = other._inv[i]->clone();
			else
				_inv[i] = NULL;
		}
	}
	std::cout << "Character " << _name << " copied by =." << std::endl;
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if(_inv[i])
			delete _inv[i];
	}
	std::cout << "Character " << _name << " destroyed!" << std::endl;
}

//	METHODS

std::string const &Character::getName() const
{
	return _name;
}


void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!_inv[i])
		{
			_inv[i] = m;
			return;
		}
	}
}

void Character::unequip(int ind)
{
	if (ind < 0 || ind > 3)
		return;
	if (_inv[ind])
	{
		_inv[ind] = 0;
	}
}


void Character::use(int ind, ICharacter &target)
{
	if (ind < 0 || ind > 3)
		return;
	if (_inv[ind])
		_inv[ind]->use(target);
}