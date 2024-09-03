#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice") {}

Ice::Ice(const Ice& obj)
{
	type = obj.type;
}

Ice& Ice::operator=(const Ice& obj)
{
	if (this == &obj) return *this;

	type = obj.type;
	return *this;
}

Ice::~Ice(void) {}

Ice* Ice::clone() const
{
	return new Ice();
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}