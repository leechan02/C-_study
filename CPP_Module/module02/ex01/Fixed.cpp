#include "Fixed.hpp"

Fixed::Fixed(void) : fixed_point(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	fixed_point = value << bits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	fixed_point = roundf(value * 256);
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

std::ostream& operator<<(std::ostream& out, const Fixed& src)
{
	out << src.toFloat();
	return out;
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(fixed_point) / 256);
}

int Fixed::toInt(void) const
{
	return (fixed_point >> bits);
}

int Fixed::getRawBits(void) const
{
	return (fixed_point);
}

void Fixed::setRawBits(int const raw)
{
	fixed_point = raw;
}