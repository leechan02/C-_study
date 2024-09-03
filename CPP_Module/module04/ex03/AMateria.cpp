#include "AMateria.hpp"

AMateria::AMateria(void) : type("default") {}

AMateria::AMateria(std::string const& type) : type(type) {}

AMateria::AMateria(const AMateria& obj) : type(obj.type) {}

AMateria& AMateria::operator=(const AMateria& obj)
{
	if (this == &obj) return *this;

	type = obj.type;
	return *this;
}

AMateria::~AMateria(void) {}

std::string const& AMateria::getType() const
{
	return type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << target.getName() << std::endl;
}