#ifndef _FIXED_HPP_
#define _FIXED_HPP_
#include <iostream>
#include <cmath>
class Fixed
{
private:
	int fixedPoint;
	static const int fracBits;

public:
	Fixed();
	Fixed(const int num);
	Fixed(const float num);
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
	
	bool operator>(const Fixed& obj) const;
	bool operator<(const Fixed& obj) const;
	bool operator<=(const Fixed& obj) const;
	bool operator>=(const Fixed& obj) const;
	bool operator==(const Fixed& obj) const;
	bool operator!=(const Fixed& obj) const;

	Fixed operator+(const Fixed& obj) const;
	Fixed operator-(const Fixed& obj) const;
	Fixed operator*(const Fixed& obj) const;
	Fixed operator/(const Fixed& obj) const;
};
std::ostream &operator<<(std::ostream &os, const Fixed &t);

#endif