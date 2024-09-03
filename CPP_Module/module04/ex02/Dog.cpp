#include "Dog.hpp"

Dog::Dog(void) : type("Dog")
{
	brain = new Brain();
	std::cout << GREEN << "Dog constructor called" << RESET << std::endl;
}

Dog::~Dog(void)
{
	delete brain;
	std::cout << RED << "Dog destructor called" << RESET << std::endl;
}

Dog::Dog(const Dog& obj) : type(obj.type)
{
	brain = new Brain(*obj.brain);
	std::cout << GREEN << "Dog Copy constructor called" << RESET << std::endl;
}

Dog& Dog::operator=(const Dog& obj)
{
	std::cout << GREEN << "Dog Copy assigment operator called" << RESET << std::endl;

	if (this == &obj) return *this;

	type = obj.type;
	delete brain;
	brain = new Brain(*obj.brain);
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "wouf" << std::endl;
}

std::string Dog::getType(void) const
{
	return (type);
}