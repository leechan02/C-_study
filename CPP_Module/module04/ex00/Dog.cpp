#include "Dog.hpp"

Dog::Dog(void) : type("Dog")
{
	std::cout << GREEN << "Dog constructor called" << RESET << std::endl;
}

Dog::~Dog(void)
{
	std::cout << RED << "Dog destructor called" << RESET << std::endl;
}

Dog::Dog(const Dog& obj) : type(obj.type)
{
	std::cout << GREEN << "Dog Copy constructor called" << RESET << std::endl;
}

Dog& Dog::operator=(const Dog& obj)
{
	if (this == &obj) return *this;

	type = obj.type;
	std::cout << GREEN << "Dog Copy assigment operator called" << RESET << std::endl;
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "wouf wouf" << std::endl;
}

std::string Dog::getType(void) const
{
	return (type);
}