#include "Cat.hpp"

Cat::Cat(void) : type("Cat")
{
	brain = new Brain();
	std::cout << GREEN << "Cat constructor called" << RESET << std::endl;
}

Cat::~Cat(void)
{
	delete brain;
	std::cout << RED << "Cat destructor called" << RESET << std::endl;
}

Cat::Cat(const Cat& obj) : type(obj.type)
{
	brain = new Brain(*obj.brain);
	std::cout << GREEN << "Cat Copy constructor called" << RESET << std::endl;
}

Cat& Cat::operator=(const Cat& obj)
{
	std::cout << GREEN << "Cat Copy assigment operator called" << RESET << std::endl;

	if (this == &obj) return *this;

	type = obj.type;
	delete brain;
	brain = new Brain(*obj.brain);
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "meow" << std::endl;
}

std::string Cat::getType(void) const
{
	return (type);
}