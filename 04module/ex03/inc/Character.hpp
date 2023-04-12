#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include <iostream>
# include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		std::string _name;
		AMateria *_inv[4];

	public:
		Character(std::string const &name);
		Character(Character const &copy);
		Character &operator=(Character const &other);
		~Character();

		std::string const &getName() const;
		void equip(AMateria *m);
		void unequip(int ind);
		void use(int ind, ICharacter &target);
};

#endif