#pragma once

#include "ClapTrap.hpp"

#define FRAGHIT 100
#define FRAGENG 100
#define FRAGATT 30

class FragTrap : public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(const FragTrap& src);
		FragTrap& operator=(const FragTrap& src);
		~FragTrap(void);
		void highFivesGuys(void);
};
