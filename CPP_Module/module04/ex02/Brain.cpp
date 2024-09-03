#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << GREEN << "Brain constructor called" << std::endl;
}

Brain::~Brain(void)
{
	std::cout << RED << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain& obj)
{
	for (int i = 0; i < 100; i++)
		ideas[i] = obj.ideas[i];
	std::cout << GREEN << "Brain Copy constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& obj)
{
	std::cout << GREEN << "Brain Copy assiment operator called" << std::endl;

	if (this == &obj) return *this;

	for (int i = 0; i < 100; i++)
		ideas[i] = obj.ideas[i];
	return *this;
}
