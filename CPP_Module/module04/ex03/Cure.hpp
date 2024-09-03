#pragma once

#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure(void);
		Cure(const Cure& obj);
		Cure& operator=(const Cure& obj);
		~Cure(void);
		Cure* clone() const;
		void use(ICharacter& target);
};