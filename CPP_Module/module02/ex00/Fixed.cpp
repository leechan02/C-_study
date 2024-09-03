#include "Fixed.hpp"

Fixed::Fixed(void) : fixed_point(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	fixed_point = src.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	fixed_point = src.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (fixed_point);
}

void Fixed::setRawBits(int const raw)
{
	fixed_point = raw;
}