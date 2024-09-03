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

		Fixed& operator=(const Fixed& src);

		bool operator>(const Fixed& src) const;
		bool operator<(const Fixed& src) const;
		bool operator>=(const Fixed& src) const;
		bool operator<=(const Fixed& src) const;
		bool operator==(const Fixed& src) const;
		bool operator!=(const Fixed& src) const;

		Fixed operator+(const Fixed& src) const;
		Fixed operator-(const Fixed& src) const;
		Fixed operator*(const Fixed& src) const;
		Fixed operator/(const Fixed& src) const;

		Fixed& operator++(void);
		Fixed operator++(int);
		Fixed& operator--(void);
		Fixed operator--(int);

		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);

		float toFloat(void) const;
		int toInt(void) const;
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream& out, const Fixed& src);