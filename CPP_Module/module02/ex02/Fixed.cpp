#include "Fixed.hpp"

Fixed::Fixed(void) : fixed_point(0) {}

Fixed::Fixed(const int value) : fixed_point(value << bits) {}

Fixed::Fixed(const float value) : fixed_point(roundf(value * 256)) {}

Fixed::Fixed(const Fixed &src) : fixed_point(src.fixed_point) {}

Fixed::~Fixed(void) {}

Fixed& Fixed::operator=(const Fixed &src)
{
	fixed_point = src.fixed_point;
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Fixed& src)
{
	out << src.toFloat();
	return out;
}

bool Fixed::operator>(const Fixed& src) const
{
	return (fixed_point > src.fixed_point);
}

bool Fixed::operator<(const Fixed& src) const
{
	return (fixed_point < src.fixed_point);
}

bool Fixed::operator>=(const Fixed& src) const
{
	return (fixed_point >= src.fixed_point);
}

bool Fixed::operator<=(const Fixed& src) const
{
	return (fixed_point <= src.fixed_point);
}

bool Fixed::operator==(const Fixed& src) const
{
	return (fixed_point == src.fixed_point);
}

bool Fixed::operator!=(const Fixed& src) const
{
	return (fixed_point != src.fixed_point);
}

Fixed Fixed::operator+(const Fixed& src) const
{
	return (Fixed(toFloat() + src.toFloat()));
}
Fixed Fixed::operator-(const Fixed& src) const
{
	return (Fixed(toFloat() - src.toFloat()));
}
Fixed Fixed::operator*(const Fixed& src) const
{
	return (Fixed(toFloat() * src.toFloat()));
}
Fixed Fixed::operator/(const Fixed& src) const
{
	return (Fixed(toFloat() / src.toFloat()));
}

Fixed& Fixed::operator++(void)
{
	fixed_point++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);

	fixed_point++;
	return tmp;
}

Fixed& Fixed::operator--(void)
{
	fixed_point--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);

	fixed_point--;
	return tmp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a <= b)
		return a;
	else
		return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a <= b)
		return a;
	else
		return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a >= b)
		return a;
	else
		return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a >= b)
		return a;
	else
		return b;
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