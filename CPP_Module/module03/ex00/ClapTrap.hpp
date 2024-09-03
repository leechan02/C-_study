#pragma once

#include <iostream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

class ClapTrap
{
	private:
		std::string name;
		int HitPoints;
		int EnergyPoints;
		int AttackDamage;
	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& src);
		ClapTrap& operator=(const ClapTrap& src);
		~ClapTrap(void);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};
