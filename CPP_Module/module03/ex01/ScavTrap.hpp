#pragma once

#include "ClapTrap.hpp"

#define SCAVHIT 100
#define SCAVENG 50
#define SCAVATT 20

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& src);
		ScavTrap& operator=(const ScavTrap& src);
		~ScavTrap(void);
		void guardGate(void);
		void attack(const std::string& target);
};
