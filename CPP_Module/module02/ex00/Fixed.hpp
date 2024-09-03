#pragma once

#include <iostream>

class Fixed
{
	private:
		int fixed_point;
		static const int bits = 8;
	public:
		Fixed(void);
		Fixed(const Fixed &src);
		~Fixed(void);
		Fixed& operator=(const Fixed &src);
		int getRawBits(void) const;
		void setRawBits(int const raw);
};
