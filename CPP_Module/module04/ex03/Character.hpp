#pragma once

#include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		AMateria* inventory[4];
		std::string name;
	public:
		Character(void);
		Character(std::string name);
		Character(const Character& obj);
		Character& operator=(const Character& obj);
		~Character(void);

		std::string const& getName(void) const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};
