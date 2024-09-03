#include "Character.hpp"

Character::Character(void) : name("default")
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(std::string name) : name(name)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(const Character& obj) : name(obj.name)
{
	for (int i = 0; i < 4; i++)
	{
		if (obj.inventory[i])
			inventory[i] = obj.inventory[i]->clone();
		else
			inventory[i] = NULL;
	}
}

Character& Character::operator=(const Character& obj)
{
	if (this == &obj) return *this;

	name = obj.name;
	for (int i = 0; i < 4; i++)
		if (inventory[i])
			delete inventory[i], inventory[i] = NULL;
	for (int i = 0; i < 4; i++)
		if (obj.inventory[i])
			inventory[i] = obj.inventory[i]->clone();
	return *this;
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
		if (inventory[i])
			delete inventory[i], inventory[i] = NULL;
}

std::string const& Character::getName(void) const
{
	return name;
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!inventory[i])
		{
			inventory[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3 || !inventory[idx])
		return ;
	
	inventory[idx] = NULL;
	for (int i = idx; i < 3; i++)
	{
		inventory[i] = inventory[i + 1];
		inventory[i + 1] = NULL;
	}
}
void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3 || !inventory[idx])
		return ;
	
	inventory[idx]->use(target);
}