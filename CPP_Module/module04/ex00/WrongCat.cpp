#include "WrongCat.hpp"

WrongCat::WrongCat(void) : type("WrongCat")
{
	std::cout << GREEN << "WrongCat constructor called" << RESET << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << RED << "WrongCat destructor called" << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat& obj) : type(obj.type)
{
	std::cout << GREEN << "WrongCat Copy constructor called" << RESET << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& obj)
{
	if (this == &obj) return *this;

	type = obj.type;
	std::cout << GREEN << "WrongCat Copy assigment operator called" << RESET << std::endl;
	return *this;
}

void WrongCat::makeSound(void) const
{
	std::cout << "meow" << std::endl;
}

std::string WrongCat::getType(void) const
{
	return (type);
}