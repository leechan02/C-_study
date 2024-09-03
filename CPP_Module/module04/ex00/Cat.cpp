#include "Cat.hpp"

Cat::Cat(void) : type("Cat")
{
	std::cout << GREEN << "Cat constructor called" << RESET << std::endl;
}

Cat::~Cat(void)
{
	std::cout << RED << "Cat destructor called" << RESET << std::endl;
}

Cat::Cat(const Cat& obj) : type(obj.type)
{
	std::cout << GREEN << "Cat Copy constructor called" << RESET << std::endl;
}

Cat& Cat::operator=(const Cat& obj)
{
	if (this == &obj) return *this;

	type = obj.type;
	std::cout << GREEN << "Cat Copy assigment operator called" << RESET << std::endl;
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