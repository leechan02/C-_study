#pragma once

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string type;
	public:
		AMateria(void);
		AMateria(std::string const& type);
		AMateria(const AMateria& obj);
		AMateria& operator=(const AMateria& obj);
		virtual ~AMateria(void);
		std::string const& getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};
