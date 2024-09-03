#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("Human")
{
	std::cout << GREEN << "WrongAnimal constructor called" << RESET << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << RED << "WrongAnimal destructor called" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj) : type(obj.type)
{
	std::cout << GREEN << "WrongAnimal Copy constructor called" << RESET << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& obj)
{
	if (this == &obj) return *this;

	type = obj.type;
	std::cout << GREEN << "WrongAnimal Copy assigment operator called" << RESET << std::endl;
	return *this;
}

void WrongAnimal::makeSound(void) const {}

std::string WrongAnimal::getType(void) const
{
	return (type);
}
