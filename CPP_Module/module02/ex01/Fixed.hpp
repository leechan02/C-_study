#pragma once

#include <iostream>

class Fixed
{
	private:
		int fixed_point;
		static const int bits = 8;
	public:
		Fixed(void);
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &src);
		~Fixed(void);
		Fixed& operator=(const Fixed &src);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& src);