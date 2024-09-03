#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure") {}

Cure::Cure(const Cure& obj)
{
	type = obj.type;
}

Cure& Cure::operator=(const Cure& obj)
{
	if (this == &obj) return *this;

	type = obj.type;
	return *this;
}

Cure::~Cure(void) {}

Cure* Cure::clone() const
{
	return new Cure();
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}