#pragma once

#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice(void);
		Ice(const Ice& obj);
		Ice& operator=(const Ice& obj);
		~Ice(void);
		Ice* clone() const;
		void use(ICharacter& target);
};